class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int rob1 = 0;
        int rob2 = 0;
        for (auto n : nums) {
            int temp = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;            
        }
        return rob2;
        
        // return dfs(nums, dp, nums.size() - 1);
    }
    
    
    //     int dfs(vector<int>& nums, vector<int>& dp, int i) {
    //         if (i == 0) {
    //             dp[i] = nums[i];
    //             return nums[i];
    //         }

    //         if (i == 1) {
    //             dp[i] = max(nums[0], nums[1]);
    //             return dp[i];
    //         }

    //         if (i < 0)
    //             return 0;        

    //         if (dp[i] != -1)
    //             return dp[i];
    //         int firstChoice = nums[i] + dfs(nums, dp, i - 2);
    //         int secondChoice = dfs(nums, dp, i - 1);
    //         dp[i] = firstChoice > secondChoice ? firstChoice : secondChoice;
    //         return dp[i];        
    //     }
};