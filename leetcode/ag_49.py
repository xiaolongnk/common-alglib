class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        from collections import defaultdict
        hp = defaultdict(list)
        for s in strs:
            a = [0] * 26
            for j in s:
                a[ord(j) - ord('a')] +=1
            hp[tuple(a)].append(s)
        return hp.values()
