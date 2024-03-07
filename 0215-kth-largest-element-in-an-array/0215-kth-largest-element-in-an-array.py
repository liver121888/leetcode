class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # try to use heapq module in python
        #         nums_heap = []
        #         for n in nums:
        #             heapq.heappush(nums_heap, n)
        #             if len(nums_heap) > k:
        #                 heapq.heappop(nums_heap)
        #         return nums_heap[0]
        
        heapq.heapify(nums)
        for i in range(len(nums) - k):
            x = heapq.heappop(nums)
        
        return nums[0]

            