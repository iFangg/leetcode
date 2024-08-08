# Solution 1
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        result = []
        low_b = newInterval[0]
        upp_b = newInterval[1]
        i = 0
        while i < len(intervals) and low_b > intervals[i][1]:
            result.append(intervals[i])
            i += 1

        while i < len(intervals) and upp_b >= intervals[i][0]:
            newInterval = [min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])]
            i += 1
        result.append(newInterval)

        while i < len(intervals):
            result.append(intervals[i])
            i += 1
        
        return result
