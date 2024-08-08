# Solution 1
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        kids = len(ratings)
        candys = [1] * kids
        for i in range(kids - 1):
            if ratings[i] < ratings[i + 1]: candys[i + 1] = max(candys[i] + 1, candys[i + 1])
        
        for i in range(kids - 2, -1, -1):
            if ratings[i + 1] < ratings[i]: candys[i] = max(candys[i + 1] + 1, candys[i])

        return sum(candys)
