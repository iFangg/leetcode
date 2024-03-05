# Solution 1
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        # test n for n < x/2
        # binary search low = 0 mid = x/4 high = x/2
        # if mid ^ 2 > x, low = mid, mid = low+hi/2, high = x/2 ...
        # if mid^2 == x return mid
        # if high - low = 1, return low 
        if x == 1: return 1
        low = 0
        high = x
        mid = int(x/2)
        while True:
            if mid * mid == x: return mid
            if high - low == 1: return low
            if mid * mid > x:
                high = mid
                mid = int((low + high)/2)
                continue
            else:
                low = mid
                mid = int((low + high)/2)
                continue



# Solution 2 (more time/space efficient)
class Solution(object):
    def mySqrt(self, x):
        if x == 1:
            return 1

        low, high = 0, x

        while low <= high:
            mid = (low + high) // 2

            if mid * mid == x:
                return mid
            elif mid * mid > x:
                high = mid - 1
            else:
                low = mid + 1

        return high  # Return high, which is the floor of the square root

