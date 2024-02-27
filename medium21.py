# Solution 1
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        numsCopy = nums.copy()
        numsLen = len(nums)
        for i in range(numsLen):
            nums[(i + k) % numsLen] = numsCopy[i]
        

# Solution 2
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        if len(nums) < k:
            k = k % len(nums)
        last_k_elements = nums[-k:]

        nums[k:] = nums[:-k]
        nums[:k] = last_k_elements
