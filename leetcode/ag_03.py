#!/bin/python2.7

##this is O(N^2) version
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s=="":
            return 0
        lt = list(s)
        maxLen = 1
        begin = 0
        o_s = enumerate(lt)
        for k,v in o_s:
            o_s1 = enumerate(lt[k+1:])
            nk = 1
            ha = [v]
            for k1, v1 in o_s1:
                nk = k1 + 1
                if v1 not in ha:
                    ha.append(v1)
                    nk = len(ha)
                else:
                    break
            if nk > maxLen:
                begin = k + 1
                maxLen = nk
        return maxLen

    def lengthOfLongestSubstringV1(self , s):
        hashmap = [-1 for i in range(256)]
        maxLen = 0
        start = 0
        for i in range(len(s)):
            currentHashVal = hashmap[ord(s[i])]
            if currentHashVal != -1:
                while(start <= currentHashVal):
                    hashmap[ord(s[start])] = -1
                    start += 1
            if i - start + 1 > maxLen:
                maxLen = i - start + 1
            hashmap[ord(s[i])] = i
        return maxLen

    def lengthOfLongestSubstringV2(self, s):
        """
        :type s: str
        :rtype: int
        """
        used = {}
        start = 0
        mx = 0
        for i,c in enumerate(s):
            if c in used and start <= used[c]:
                start = used[c] + 1
            else:
                mx = max(mx, i - start + 1)
            used[c] = i
        return mx

def run():
    s = Solution()
    test = "casdkfalsdfjuiy"
    print s.lengthOfLongestSubstringV1(test)
