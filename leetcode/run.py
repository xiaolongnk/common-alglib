#!/usr/bin/python
#coding:utf8
import sys
import os
import traceback


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
    file_name = sys.argv[1]
    try:
        if not file_name.endswith(".py"):
            file_name = file_name + ".py"
        if not os.path.exists(file_name):
            raise Exception("SCRIPT [ %s ] NOT FOUND!"%(file_name))
        module_name = file_name.split('.')[0]
        sys.path.append(file_name)
        ss = "from " + module_name + " import run"
        exec(ss)
        print (bcolors.HEADER+"RESULTS [%s] ARE AS FOLLOWS:"+bcolors.ENDC)\
		%(file_name)
        run()
    except Exception as e:
        traceback.print_exc()
