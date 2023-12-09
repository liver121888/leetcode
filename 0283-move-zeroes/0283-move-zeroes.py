class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        id = 0

        for i in range(len(nums)):
            if nums[i] != 0:
                temp = nums[i]
                nums[i] = nums[id]
                nums[id] = temp
                id += 1