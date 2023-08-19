class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        ans = []
        cur_sum = 0
        
        def backtrack(candidates, target, combination, ans):
            if target == 0:
                ans.append(combination)
                return
            for i in range(len(candidates)):
                if candidates[i] > target:
                    return
                
                backtrack(candidates[i:], target - candidates[i], combination + [candidates[i]], ans )            
  
        backtrack(candidates, target, [], ans)
        return ans
        
