# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) == 0:
            return []
        intervals = sorted(intervals, key = lambda x : x.start)

        ans = []
        for inv in intervals:
            if len(ans) ==0:
                ans.append(inv)
            else:
                if inv.start <= ans[-1].end:
                    ans[-1].end = max(ans[-1].end, inv.end)
                else:
                    ans.append(inv)
        return ans

            

