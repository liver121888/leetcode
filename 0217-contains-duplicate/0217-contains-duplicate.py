class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return True if len(nums) > len({n for n in nums}) else False