class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        inserted = False
        for i in range(n):
            if not inserted and intervals[i][0] > newInterval[0]:
                intervals.insert(i, newInterval)
                inserted = True
        if not inserted:
            intervals.append(newInterval)
        
        print(intervals)
        print(n)
        i = 1
        while i < len(intervals):
            if intervals[i][0] <= intervals[i-1][1]:
                intervals[i-1][1] = max(intervals[i-1][1],intervals[i][1])
                intervals.pop(i)
            else:
                i+=1        
        return intervals
                