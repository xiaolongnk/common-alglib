#!/usr/bin/python
#coding:utf8
import sys
import os
class bcolors:
    HEADER  = '\033[95m'
    OKBLUE  = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL    = '\033[91m'
    ENDC    = '\033[0m'
    BOLD    = '\033[1m'
    UNDERLINE = '\033[4m'

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print bcolors.WARNING + "USAGE:[ ./run.py your_script_name ]" + bcolors.ENDC;
        sys.exit(1)
    fileName = sys.argv[1]
    try:
        if fileName.endswith(".py"):
            if os.path.exists(fileName):
                fileName = fileName.split('.')[0]
            else:
                raise Exception("SCRIPT [ %s ] NOT FOUND!"%(fileName))
        elif os.path.exists(fileName+".py"):
            ss = "from " + fileName + " import run"
        else:
            raise Exception("SCRIPT [ %s ] NOT FOUND!"%(fileName+".py"))
        exec(ss)
        print (bcolors.HEADER+"RESULTS [%s] ARE AS FOLLOWS:"+bcolors.ENDC)\
		%(fileName)
        run()
    except Exception as e:
        print (bcolors.FAIL + e.args[0] + bcolors.ENDC)
