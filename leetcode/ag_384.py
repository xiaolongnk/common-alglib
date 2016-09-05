import random
import copy

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        :type size: int
        """
        self.nums = copy.deepcopy(nums)
        self.orig_nums = copy.deepcopy(nums)
        

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.nums = copy.deepcopy(self.orig_nums)
        return self.nums
        
    def show(self):
        print self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        random.shuffle(self.nums)
        return self.nums


def run():
    nums =[1,2,3,4,9,12,24]
    ns = Solution(nums)
    print ns.shuffle()
    print ns.reset()
    print ns.shuffle()
    print ns.reset()
