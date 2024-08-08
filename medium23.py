# Solution 1
class Solution(object):
    def findPeakElement(self, nums):
        if len(nums) <= 1: return 0
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums[0] > nums[1]: return 0
        if nums[len(nums) - 1] > nums[len(nums) - 2]: return len(nums) - 1
        lo = 1
        hi = len(nums) - 2
        while lo <= hi:
            if nums[lo - 1] < nums[lo] and nums[lo + 1] < nums[lo]: return lo
            if nums[hi - 1] < nums[hi] and nums[hi + 1] < nums[hi]: return hi
            lo += 1
            hi -= 1


# Solution 2
class Solution(object):
    def findPeakElement(self, nums):
        l, r = 0, len(nums) - 1

        while l <= r:
            m = ((l + r) // 2)
            if m < len(nums) - 1 and nums[m] < nums[m + 1]:
                l = m + 1
            elif m > 0 and nums[m] < nums[m - 1]:
                r = m - 1
            else:
                return m      
        
