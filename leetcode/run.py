#coding:utf8
import sys


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print "参数不全,请指定脚本名";
        sys.exit(1)
    fileName = sys.argv[1]
    try:
        ss = "from " + fileName + " import run"
        print ss,"\n"
        exec(ss)
    except:
        print "Script not found";
    run()
