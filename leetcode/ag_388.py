#coding:utf8

'''
@desc: 感觉这个题目还是挺复杂的，虽然代码很简单，但是要在比较短的时间内解决还是很不容易的。
       如果我面试被问到，肯定是搞不出来的，如果没有做过这个题目的话。
       可以做如下的变形：
       @1: 打印出最长的文件
       @2: 打印出所有的空目录和文件

@date: 2016-11-04 15:31
'''

GLOBAL_DEBUG = 0

class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        max_len = 0
        stack = []
        dirs = input.split('\n')
        for i in dirs:
            dirname = i.strip('\t')
            tabs = len(i) - len(dirname)
            while tabs < len(stack):
                stack.pop()
            stack.append(len(dirname))
            if '.' in dirname:
                if max_len < sum(stack) + len(stack) - 1:
                    max_len = sum(stack) + len(stack) - 1
        return max_len

class NewSolution(object):

    def lengthLongestPath(self , yinput):
        dirs = yinput.split('\n')
        allfiles = []
        filecnt = 0
        for i in dirs:
            filecnt = filecnt + 1
            if '.' in i:
                if GLOBAL_DEBUG:
                    print "filecnt for %s is %d"%(i,filecnt)
                tmpfile = i.strip('\t')
                tabs = len(i) - len(i.strip('\t'))
                flag = 0
                while tabs >= 0:
                    ttt = ''
                    searchcnt = 0
                    for j in dirs:
                        searchcnt += 1
                        lenoftabs = len(j) -len(j.strip('\t'))
                        if tabs == 0  and lenoftabs == 0 and flag == 0:
                            ttt = j
                            break
                        if searchcnt > filecnt:
                            break
                        if '.' in j:
                            continue
                        if lenoftabs + 1 == tabs:
                            if lenoftabs == 0:
                                flag = 1
                            ttt = j.strip('\t')
                        if GLOBAL_DEBUG:
                            print "%s  , %s , %s"%(filecnt , j , tabs)
                    if ttt:
                        tmpfile = ttt + '/' + tmpfile
                    tabs = tabs - 1
                print tmpfile




if __name__ == '__main__':
    s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext\n\tsubdir3\n\t\thello.ext\n\twww\n\t\thello\n\t\t\ttest\n\t\t\t\txxx.txt"
    so = NewSolution()
    so.lengthLongestPath(s)
