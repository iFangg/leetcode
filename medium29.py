# Solution 1
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # start at end
        # test to see which indexes can reach the tail
        # add indexes to queue and retest until we reach the head or we don't reach it
        if len(nums) == 1 and nums[0] > 0: return True
        tail = len(nums) - 1
        curr = tail
        queue = [tail]
        while queue:
            # print(queue)
            curr = queue.pop(0)
            if curr == 0: return True
            for i in range(curr - 1, -1, -1):
                if i + nums[i] >= curr: 
                    queue.append(i)
                    break
        
        if curr != 0: return False
        return True


# Solution 2
    def canJump(self, nums: List[int]) -> bool:
        # start at end
        # test to see which indexes can reach the tail
        # add indexes to queue and retest until we reach the head or we don't reach it
        if len(nums) == 1 and nums[0] > 0: return True
        tail = len(nums) - 1
        curr = tail
        for i in range(tail - 1, -1, -1):
            if i + nums[i] >= curr: curr = i
        
        return curr == 0
