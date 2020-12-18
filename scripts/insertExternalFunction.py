#!/usr/bin/env python3

import os
import sys, argparse
import subprocess
import numpy as np

#take header file as a command line argument -ext or --externalFunction
#usage is as python3 insertExternalFunction.py -ext/--externalFunction abc

parser = argparse.ArgumentParser()
parser = argparse.ArgumentParser(add_help=False)
parser.add_argument("-h", "--help", action="help", default=argparse.SUPPRESS,
                    help="This is just a simple script for adding external functions to CutLang automatically.\n Usage is as python3 insertExternalFunction.py -ext/--externalFunction abc.\n As a result it will add abc.h to the necessary places, so you can use your newly defined variable seamlessly.\n")
                    
parser.add_argument("-ext","--externalFunction",required=True,help="name of the header file which contains your external function")
args = parser.parse_args()

#this function just takes a string and places it to certain line number of a certain file.
def insertStringToFileAtLine(str, fileName, lineNumber):
    with open (fileName,'r') as f:
        lines = f.readlines()
    with open(fileName,'w') as f:
        for i,line in enumerate(lines):
            if i == lineNumber:
                f.write(str+"\n")
            f.write(line)
    s = "inserted {} to file {} at line {}".format(str, fileName, lineNumber)
    return s

#this part of the code operates if the externalFunction argument is given
if args.externalFunction:
    
    #get the line number of the last occurance of '#include' at ExternFunctions.h
    lineNumber1 = int(subprocess.getoutput("awk '/#include/ { ln = FNR } END { print ln }' ExternFunctions.h"))
    print(lineNumber1)
    #insert new external function header
    str1 = "#include \"{}.h\"".format(args.externalFunction)
    print(str1)
    insertStringToFileAtLine(str1, "ExternFunctions.h", lineNumber1)
    #get the line number of the last occurance of 'return' at ../CLA/parse.l
    lineNumber2 = int(subprocess.getoutput("awk '/return/ { ln = FNR } END { print ln }' ../CLA/parse.l"))
    print(lineNumber2)
    #return the new external function
    str2 = "\"{}\" return {};".format(args.externalFunction,args.externalFunction.upper())
    print(str2)
    insertStringToFileAtLine(str2, "../CLA/parse.l", lineNumber2)
    #get the line number of the last occurance of 'token' at ../CLA/parse.y
    lineNumber3 = int(subprocess.getoutput("awk '/token/ { ln = FNR } END { print ln }' ../CLA/parse.y"))
    print(lineNumber3)
    #insert new token for our new external function
    str3 = "%token {}".format(args.externalFunction.upper())
    print(str3)
    insertStringToFileAtLine(str3, "../CLA/parse.y", lineNumber3)
    
    #according the argument of the new external function, it will be classified as userFuncA, B, C, D or E.
    str4 = "awk /{}/ {}.h  | awk -F\"[()]\" '{{print $2}}' ".format(args.externalFunction, args.externalFunction)
    argumentOfExtern = subprocess.getoutput(str4)
    tokenizeArgument = argumentOfExtern.split(",")
    print(tokenizeArgument)
    numTLorentz = sum('std::vector<TLorentzVector>' in s for s in tokenizeArgument)
    numInt = sum('int' in s for s in tokenizeArgument)
    numTVector2 = sum('TVector2' in s for s in tokenizeArgument)
    str5=" "
    if numTLorentz == 1 and numInt == 1 and numTVector2 == 0:
        print("userFuncA")
        str5 = """    | {} \'(\' ID \',\' INT \',\' INT \'\)\' {{ map<string,Node*>::iterator it = ObjectCuts->find($3);
                               if(it == ObjectCuts->end()) {{
                                        std::string message = \"Object not defined: \";
                                        message += $3;
                                        yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                        YYERROR;
                               }} else {{
                                      int seed =$5;
                                      int assoc=$7;
                                      //int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                      int type=100*seed+assoc;
                                      $$=new SFuncNode(userfuncA, {}, type, \"{}\" , it->second);
                               }}
                       }}""".format(args.externalFunction.upper(),args.externalFunction,args.externalFunction.upper())
    elif numTLorentz == 1 and numInt == 0 and numTVector2 == 0:
        print("userFuncB")
        str5 = """    | {} \'\(\' ID \'\)\' {{ map<string,Node*>::iterator it = ObjectCuts->find($3);
                                if(it == ObjectCuts->end()) {{
                                         std::string message = \"Object not defined: \";
                                         message += $3;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                }} else {{
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncB, {}, type, $3 , it->second);
                                }}
                        }}""".format(args.externalFunction.upper(),args.externalFunction)
    elif numTLorentz == 1 and numInt == 0 and numTVector2 == 1:
        print("userFuncC")
        str5 = """"      | {} '(' ID ',' MET ')'{{   map<string,Node*>::iterator it = ObjectCuts->find($3);
                                   if (it == ObjectCuts->end()) {{
                                         std::string message = "Object not defined: ";
                                         message += $3;
                                         yyerror(NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,message.c_str());
                                         YYERROR;
                                   }} else {{
                                         int type=((ObjectNode*)it->second)->type; // type is JETS or FJETS etc..
                                         $$=new SFuncNode(userfuncC, {}, type, $3 , it->second);
                                   }}
                               }}""".format(args.externalFunction.upper(),args.externalFunction)

    else: print("CutLang doesn't know such a function yet")
    
    lineNumber4 = int(subprocess.getoutput("awk '/userfuncA/ { ln = FNR } END { print ln }' ../CLA/parse.y"))
    print(lineNumber4)
    print(str5)
    lineNumber4 = lineNumber4+2
    insertStringToFileAtLine(str5, "../CLA/parse.y", lineNumber4)

    

 
