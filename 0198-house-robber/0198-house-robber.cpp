// this is a dynamic programming problem
// we can do a dfs method, starting from index 0
// all the way to the end
// in each index, we can choose to rob or not to rob
// rob(i) = max(rob(i-2) + nums[i], rob(i-1))
// time: O(2^n) since we have 2 options in each position
// space: O(n) since we recursive calls

// a way to dp is store the rob(i-1) result
// so next time we only O(1) the solution
// time: O(n), every index calculate once
// space: O(n), there is a dp array

// bottom-up
// if only 1 house
// return nums[0]
// if 2 houses
// return max(nums[1], nums[0])

// f(i) = max(nums[i] + dp[i - 2], dp[i-1])


class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        // base case: size == 1
        if (n == 1)
            return nums[0];

        // base case: size == 2
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        }
        
        return dp[n-1];
    }
};