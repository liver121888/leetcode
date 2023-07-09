class Solution:
    def alternatingSubarray(self, nums: List[int]) -> int:
        left = 0
        maxLen = 0
        n = len(nums)
        state = float('inf')
        for right in range(1, n):
            diff = nums[right] - nums[right - 1]
            if diff == state * -1:
                state *= -1
                maxLen = max(maxLen, right - left + 1)
            else:
                if diff == 1:
                    state = diff
                    left = right - 1
                    maxLen = max(maxLen, right - left + 1)
                else:
                    state = float('inf')

        return -1 if maxLen == 0 else maxLen