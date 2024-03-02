class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            goal = target - numbers[left]
            
            if goal > numbers[right]:
                left += 1
            elif goal < numbers[right]:
                right -= 1
            else:
                return [left + 1, right + 1]