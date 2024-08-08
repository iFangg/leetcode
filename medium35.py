# Solution 1
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        result = []
        left = 0
        right = len(numbers) - 1
        while left < right:
            lr_sum = numbers[left] + numbers[right]
            if lr_sum == target:
                return [left + 1, right + 1]
            if lr_sum > target:
                right -= 1
            else:
                left += 1

        return result
