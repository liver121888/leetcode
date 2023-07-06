class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        minLength = float('inf')
        current = 0
        left = right = 0 
        for right in range(n):
            current += nums[right] 
            while current >= target:
                minLength = min(minLength, right - left + 1)
                current -= nums[left]
                left += 1
                    
        return minLength if minLength != float('inf') else 0