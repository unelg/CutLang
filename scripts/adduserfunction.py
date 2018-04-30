'''
Script for adding user defined functions into CutLang
run as python adduserfunction.py <functionname>
To clean an already added function, run python adduserfunction.py <functionname> --clean
'''

#!/usr/bin/env python
import os,sys
from string import *
from optparse import OptionParser

# Parsing options
usage = "Usage: python %prog <functionname> [options]"
parser = OptionParser(usage=usage)
parser.add_option("--clean", action="store_true", dest="clean", default=False, help="clean the function")
#parser.add_option("--func", action="store_true", dest="name", default=False, help="function name")
(option,args) = parser.parse_args()

# Get the user function name
if len(args) < 1:
    print "Please specify the name of the user function"
    print "For help, run python %s -h" % (sys.argv[0])
    sys.exit()
name = args[0]
clean = option.clean

# Put variables in a dictionary
names = {}
names['name'] = name
names['upname'] = names['name'].upper()

if not clean:
    # User function template
    userfunctmp = '''

//How to define a user function?
//write such a .h file and include it in dbxCut.cpp
//
#ifndef DBX_%(upname)s_H
#define DBX_%(upname)s_H

class dbxCut%(name)s : public dbxCut {
 public:
      dbxCut%(name)s: dbxCut("}%(name)s"){}
      dbxCut%(name)s(std::vector<int> ts, std::vector<int> is, int v ): dbxCut("}s(name)s",ts,is,v){}

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
    funcfile = '../analysis_core/dbx_'+names['name']+'.h'
    open(funcfile, 'w').write(userfunccont)

    print '\nCreated the user function analysis_core/dbx_'+names['name']+'.h. \nPlease edit and recompile.\n'

else:
    funcfile = '../analysis_core/dbx_'+names['name']+'.h'
    if os.path.exists(funcfile):
        os.remove(funcfile)

# Add the relevant information to dbxCut.h
incname = 'dbx_'+name+'.h'
funcname = 'dbxCut'+name
incline = '#include "'+incname+'"\n'
funcline = '                    cutlist.push_back(new '+funcname+'());\n'

dcut = open('../analysis_core/dbxCut.cpp', 'r').readlines()
dcutall = open('../analysis_core/dbxCut.cpp', 'r').read()

if clean:
    if incline not in dcutall and funcline not in dcutall and not os.path.exists('../analysis_core/dbxCut_'+name+'.h'):
        print 'User function '+name+' already nonexistent.  Nothing to clean.'
        sys.exit(0)
    dcutall = dcutall.replace(incline, '')    
    dcutall = dcutall.replace(funcline, '')
    open('../analysis_core/dbxCut.cpp', 'w').write(dcutall)    
    print 'Cleaned the user function '+name
    sys.exit(0)

if incname in dcutall:
    print 'include already in dbxCut.h, deleting...'
    dcutall.replace(incline, '')
if funcname in dcutall:
    print 'function already in dbxCut.h cutlist, deleting...'
    dcutall.replace(incline, '')

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

addfunc = dcut[ifunc] + funcline
addinc = dcut[iinc] + incline

dcutall = dcutall.replace(dcut[ifunc], addfunc)
dcutall = dcutall.replace(dcut[iinc], addinc)

open('../analysis_core/dbxCut.cpp', 'w').write(dcutall)

print 'Made necessary changes in analysis_core/dbxCut.cpp.\n'

