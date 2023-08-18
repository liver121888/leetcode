class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [0] * n
        suff = [0] * n
        ans = [0] * n
        
        pre[0] = 1
        for i in range(1, n):
            pre[i] = pre[i - 1] * nums[i - 1]
        
        suff[n - 1] = 1
        for i in range(1, n):
            suff[n - 1 - i] = suff[n - i] * nums[n - i]
        
        print(pre)
        print(suff)
    
        for i in range(n):
            ans[i] = pre[i] * suff[i]
        
        return ans

            
            
