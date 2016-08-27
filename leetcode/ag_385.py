class NestedInteger(object):
    def __init__(self,elem=None):
        pass
    def add(self , a):
        pass


class Solution(object):

    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        lst = []
        last_ic_ix = 0
        if s[0] != '[':
            return NestedInteger(int(s))
        for i in range(0,len(s)):
            if s[i] == '[':
                ns = NestedInteger()
                lst.append(ns)
                last_ic_ix = i
            elif s[i] == ',' or s[i] == ']':
                ss = s[last_ic_ix+1:i]
                if ss != '':
                    tmp = int(ss)
                    lst[len(lst)-1].add(NestedInteger(tmp))
                last_ic_ix = i
                if s[i] == ']':
                    top = lst.pop()
                    if len(lst) == 0:
                        return top
                    lst[len(lst)-1].add(top)
        return False



if __name__=='__main__':
    ns = Solution()
    print ns.deserialize("[123,3,[32,2,[33,24],3]]");
