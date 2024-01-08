class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curState;
        dfs(ans, curState, nums, 0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans,
             vector<int> curState,
             vector<int>& nums,
             int i) {
        // leaves check
        if (i == nums.size()) {
            ans.push_back(curState);
            return;
        }
        
        // here we check all possibility that includes number at nums[i]
        curState.push_back(nums[i]);
        dfs(ans, curState, nums, i + 1);
        curState.pop_back();
        
        // here we check all possibility that not includes
        // number at nums[i]
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        dfs(ans, curState, nums, i + 1);
    }
    
};