class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        indices = [-2] * (2*n + 1)
        # at start, count = 0
        indices[n] = -1
        count = 0
        maxLen = 0
        for i, num in enumerate(nums):
            if num == 0:
                count -= 1
            else:
                count += 1
            if indices[count + n] < -1:
                # record the index of first encounter 
                indices[count + n] = i              
            else:
                # not first encounter, cal maxLen
                maxLen = max(maxLen, i - indices[count + n])
            
        return maxLen