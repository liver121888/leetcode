class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        k = len(nums)//2
        # print(nums[k::-1])
        # print(nums[:k:-1])
        
        # left subArray
        lSum = self.maxSubArray(nums[:k])
        # right subArray
        rSum = self.maxSubArray(nums[k:]) 
        
        cSum = self.crossMaxSubArray(nums, k)
        return max(lSum, rSum, cSum)
    
    def crossMaxSubArray(self, nums: List[int], mid: int) -> int:
        rSum = lSum = -10**5
        total = 0
        for n in nums[mid-1::-1]:
            total += n
            if total > lSum:
                lSum = total
        
        total = 0
        for n in nums[mid:]:
            total += n
            if total > rSum:
                rSum = total
        
        return lSum + rSum

        
        
        