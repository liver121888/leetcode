class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        // base case
        //         dp[nums.size() - 1] = nums[nums.size() - 1];

        //         for (int i = nums.size() - 2; i >= 0; i--) {



        //         }
        
        return dfs(nums, dp, nums.size() - 1);
    }
    
    
    int dfs(vector<int>& nums, vector<int>& dp, int i) {
        if (i == 0) {
            dp[i] = nums[i];
            return nums[i];
        }
        
        if (i == 1) {
            dp[i] = max(nums[0], nums[1]);
            return dp[i];
        }

        if (i < 0)
            return 0;        
        
        if (dp[i] != -1)
            return dp[i];
        int firstChoice = nums[i] + dfs(nums, dp, i - 2);
        int secondChoice = dfs(nums, dp, i - 1);
        dp[i] = firstChoice > secondChoice ? firstChoice : secondChoice;
        return dp[i];        
    }
};