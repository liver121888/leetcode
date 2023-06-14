class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        aMap = {}
        n = len(nums)
        
        for i in range(n):
            aMap[nums[i]] = i
        
        for i in range(n):
            rest = target - nums[i]
            if rest in aMap and aMap[rest] != i:
                return [aMap[rest], i]
            
        return []