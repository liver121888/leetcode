class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        # Boyer–Moore Majority Vote Algorithm
        cnt, prev = 0, None
        for element in nums:
            if element == prev:
                cnt += 1
            else:
                if cnt == 0:
                    prev = element
                    cnt = 1
                else:
                    cnt -= 1

        return prev
                
        