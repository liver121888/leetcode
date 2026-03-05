class Solution {


public:

    // nums = [2,3,1,1,4]
    // n = 5, we want to reach 4
    // [f, f, f, f, t]

    // [3,2,1,0,4]
    // [f, f, f, f, t]

    // time: O(n^2)
    // sapce: O(n)
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        // we want to reach n-1

        vector<bool> dp(n, false);

        // dp save true or false
        dp[n-1] = true; // beacuse it can always reach it self

        // dp[i] = (dp[i + 0] || dp[i + 1] || dp[i + nums[i]]);
        // we also need to check if i + nums[0] .. nums[i] is valid

        for (int i = n - 2; i >= 0; i--) {
            bool canJump = false;
            for (int j = 0; j <= nums[i]; j++) {
                int idx = i+j;
                // valid
                if (idx < n)
                    canJump = canJump || dp[idx]; 
            }
            dp[i] = canJump;
        }
        return dp[0];
    }


    // bool bt(vector<int>& nums, vector<bool>& visited, int cur) {

    //     // base case
    //     if (cur == nums.size() - 1)
    //         return true;

    //     if (visited[cur] || cur >= nums.size())
    //         return false;

    //     visited[cur] = true;

    //     int maxLen = nums[cur];
    //     for (int l = 0; l <= maxLen; l++) {
    //         if (bt(nums, visited, cur + l))
    //             return true;
    //     }
    //     return false;

    // }

    // bool canJump(vector<int>& nums) {
    //     vector<bool> visited(nums.size(), false);
    //     // unordered_map
    //     return bt(nums, visited, 0);
    // }
};

// [2,3,1,1,4]