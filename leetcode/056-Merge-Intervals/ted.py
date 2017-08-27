# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        
        if not intervals:
            return []
        
        intervals.sort(key=lambda interval:interval.start)
        
        interval, answers = None, []
        
        for i in range(0, len(intervals)):
            if not interval:
                interval = intervals[i]
            elif interval.end >= intervals[i].start:
                interval.end = max(interval.end, intervals[i].end)
            else:
                answers.append(interval)
                interval = intervals[i]
                
        if interval:
            answers.append(interval)
            
        return answers
