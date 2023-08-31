class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        n = len(height)
        right = n - 1
        ans = 0
        while left < right:
            ans = max(ans, (right - left) * min(height[right], height[left]))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
                            
        return ans