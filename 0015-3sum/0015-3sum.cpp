class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        # three pointers
        for left in range(n - 2):
            if left > 0 and nums[left] == nums[left - 1]:
                continue 
            mid = left + 1
            right = n - 1
            
            while mid < right:
                curSum = nums[left] + nums[right] + nums[mid]
                if curSum > 0:
                    right -= 1
                elif curSum < 0:
                    mid += 1
                else:
                    ans.append([nums[left], nums[mid], nums[right]])
                    while mid < right and nums[mid] == nums[mid + 1]:
                        mid += 1
                    while mid < right and nums[right] == nums[right - 1]:
                        right -= 1
                    mid += 1
                    right -= 1
        return ans
        
                    