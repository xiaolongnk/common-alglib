class Solution(object):
    def nextPermutation(self, nums):
        mlen = len(nums)
        if mlen <= 0: 
            return
        i = mlen - 1
        while i > 0:
            if nums[i] > nums[i-1]:
                break;
            i-=1
        if i :
            j = mlen - 1
            while j > i - 1:
                if nums[j] > nums[i-1]:
                    nums[j] = nums[j] ^ nums[i-1]
                    nums[i-1] = nums[j] ^ nums[i-1]
                    nums[j] = nums[j] ^ nums[i-1]
                    break
                j-=1
        end = mlen - 1
        while  i < end:
            nums[i] = nums[i] ^ nums[end]
            nums[end] = nums[i] ^ nums[end]
            nums[i] = nums[i] ^ nums[end]
            i+= 1
            end -= 1


def run():
    so = Solution()
    ss = [1,3,2,1]
    print ss
    so.nextPermutation(ss)
    print ss
