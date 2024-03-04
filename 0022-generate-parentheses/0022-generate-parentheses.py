class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        num_left = 0
        num_right = 0
        ans = []
        
        def dfs(cur_state, num_left, num_right):
            if num_left + num_right == 2 * n:
                ans.append(cur_state)
                return
            
            if num_left < n:
                dfs(cur_state + "(", num_left + 1, num_right)
            # reset cur_state or create new cur_state
            if num_left > num_right:
                dfs(cur_state + ")", num_left, num_right + 1)
            return
            
            
        
        cur_state = ""

        dfs(cur_state, num_left, num_right)
        return ans