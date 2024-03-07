class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 1
        
        l = 0
        r = 0
        
        while r < len(nums):
            if nums[l] == nums[r]:
                r+=1
            else:
                nums[l + 1] = nums[r]
                l += 1
                r += 1
                k += 1
        return k
        