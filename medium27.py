# Solution 1
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals or len(intervals) == 1: return intervals
        intervals.sort(key = lambda x: x[0])
        merged = [intervals[0]]

        for intv in intervals:
            if merged[-1][1] < intv[0]: merged.append(intv)
            else: merged[-1][1] = max(merged[-1][1], intv[1])

        return merged


# Solution 2
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals or len(intervals) == 1:
            return intervals
        
        # Initialize the result list
        merged = []
        
        # Sort intervals based on the start time (we will modify the original list to sort)
        intervals.sort(key=lambda x: x[0])
        
        # Iterate over sorted intervals and merge them
        current_start, current_end = intervals[0]
        
        for i in range(1, len(intervals)):
            next_start, next_end = intervals[i]
            
            if next_start <= current_end:
                # Overlapping intervals, merge them
                current_end = max(current_end, next_end)
            else:
                # Non-overlapping intervals, add the current merged interval to result
                merged.append([current_start, current_end])
                # Update current interval to the next one
                current_start, current_end = next_start, next_end
        
        # Add the last merged interval to the result
        merged.append([current_start, current_end])
        
        return merged
