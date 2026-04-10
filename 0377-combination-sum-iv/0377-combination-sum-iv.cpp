
// looks like a dp questions
// we can take a arbitrary number of the same number
// what will be our dp relation?
// dp[amount] = number of possible combinations that sums up to amount
// dp[amount] = sum(for i to nums.size() dp[amount - nums[i]])
// the larger amount is depend on lower amount
// what would be the base case?
// dp[0] = 0 because 1 <= nums[i] <= 1000

// dp [target + 1] to include 0

// Follow up: What if negative numbers are allowed in the given array? 
// How does it change the problem? 
// What limitation we need to add to the question to allow negative numbers?

class Solution {
public:

    //  nums = [1,2,3], target = 4
    // dp [1 0 0 0 0]
    // dp [1 1 0 0 0]
    // dp[2] = 1 + 1 = 2
    // dp [1 1 2 4 0]
    // dp [3] = 4
    // dp [4] = 7

    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        vector<unsigned long long> dp(target + 1, 0);
        // single way to not picking anything to get amount 0
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << " " << nums[j] << endl;
                if (i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};