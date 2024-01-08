class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curState;
        dfs(ans, nums, curState, 0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& nums, 
             vector<int>& curState, int i) {
        if (i >= nums.size()) {
            ans.push_back(curState);
            return;
        }
        
        // two subproblem
        // with cur num
        curState.push_back(nums[i]);
        dfs(ans, nums, curState, i + 1);
        // without cur num
        curState.pop_back();
        dfs(ans, nums, curState, i + 1);
    }
    
};