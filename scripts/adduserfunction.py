#!/usr/bin/env python
'''
#Script for adding (or deleting) user defined functions into CutLang
#run as python adduserfunction.py <functionname>
#To delete an already added function, run python adduserfunction.py <functionname> --clean
'''

import os,sys
from string import *
from optparse import OptionParser

# Parsing options
usage = "Usage: python %prog <functionname> [options]"
parser = OptionParser(usage=usage)
parser.add_option("--delete", action="store_true", dest="delete", default=False, help="delete the function")
(option,args) = parser.parse_args()

# Get the user function name
if len(args) < 1:
    print "Please specify the name of the user function"
    print "For help, run python %s -h" % (sys.argv[0])
    sys.exit()
name = args[0]
delete = option.delete

# Put variables in a dictionary
names = {}
names['name'] = name
names['upname'] = names['name'].upper()


# Create (or delete) the header for the user function
funcfile = '../analysis_core/dbx_'+names['name']+'.h'

# Create the user function header
if not delete:
    # Check if the header already exists
    if os.path.exists(funcfile):
        question = 'User function header '+funcfile+' already exists.  Do you want to delete?'
        yes = {'yes','y', 'ye', ''}
        no = {'no','n'}
        ianswer = -1
        while ianswer == -1:
            answer = str(raw_input(question+' (y/n): ')).lower().strip()
            if answer[0] in yes:
                print 'Deleting '+funcfile
                ianswer = 1
            if answer[0] in no:
                print 'Keeping '+funcfile+' and exiting.'
                ianswer = 0
                sys.exit(0)

    # User function template
    userfunctmp = '''
//How to define a user function?
//write such a .h file and include it in dbxCut.cpp
//
#ifndef DBX_%(upname)s_H
#define DBX_%(upname)s_H

class dbxCut%(name)s : public dbxCut {
 public:
      dbxCut%(name)s: dbxCut("%(name)s"){}
      dbxCut%(name)s(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("s(name)s",ts,is,v){}

      bool select(AnalysisObjects *ao){
          float result;
          result=calc(ao);
          return (Ccompare(result) ); 
      }
      float calc(AnalysisObjects *ao){
         float retval;

         // ***********************************
         // Write your own code here
         // ***********************************
         
         return retval;
}
private:
};

#endif

'''
    # Make the content of the user function by inserting the function name
    userfunccont = userfunctmp % names

    # Copy the contents of the user function under analysis_core
    open(funcfile, 'w').write(userfunccont)

    print '\nCreated the user function analysis_core/dbx_'+names['name']+'.h. \nPlease edit and recompile.\n'

# Delete the user function header
else:
    if os.path.exists(funcfile):
        os.remove(funcfile)

# Add (or delete) user function information to (from) dbxCut.h
incname = 'dbx_'+name+'.h'
funcname = 'dbxCut'+name
incline = '#include "'+incname+'"\n'
funcline = '                    cutlist.push_back(new '+funcname+'());\n'

dcut = open('../analysis_core/dbxCut.cpp', 'r').readlines()
dcutall = open('../analysis_core/dbxCut.cpp', 'r').read()

# Add user function information to dbxCut.h
if not delete:
    # Check if the information is already in dbxCut.h, if so, delete
    if incname in dcutall:
        print 'include already in dbxCut.h, deleting...'
        dcutall.replace(incline, '')
    if funcname in dcutall:
        print 'function already in dbxCut.h cutlist, deleting...'
        dcutall.replace(incline, '')

    # Find the place to add the information
    ifunc = 0
    for i in range(len(dcut)-1, -1, -1):
        if "cutlist.push_back" in dcut[i]:
            ifunc = i
            break
    iinc = 0
    for i in range(len(dcut)-1, -1, -1):
        if "#include" in dcut[i]:
            iinc = i
            break

    # Add the information
    addfunc = dcut[ifunc] + funcline
    addinc = dcut[iinc] + incline
    dcutall = dcutall.replace(dcut[ifunc], addfunc)
    dcutall = dcutall.replace(dcut[iinc], addinc)

    # Write the new content into dbxCut.cpp
    open('../analysis_core/dbxCut.cpp', 'w').write(dcutall)

    print 'Made necessary changes in analysis_core/dbxCut.cpp .\n'

# Delete user function information from dbxCut.h
else:
    if incline not in dcutall and funcline not in dcutall and not os.path.exists('../analysis_core/dbxCut_'+name+'.h'):
        print 'User function '+name+' already nonexistent.  Nothing to delete.'
        sys.exit(0)
    dcutall = dcutall.replace(incline, '')    
    dcutall = dcutall.replace(funcline, '')
    open('../analysis_core/dbxCut.cpp', 'w').write(dcutall)    
    print 'Deleted the user function '+name

