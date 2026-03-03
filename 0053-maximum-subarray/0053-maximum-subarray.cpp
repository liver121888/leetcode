class Solution {
public:


    // why we cannot use sliding window
    // it has negative numbers so expanding not resulting larger value
    // we can use dp
    // expanding from one array and for each position the dp stores the ans 
    // that is, up until now the largest sum

    // recursion, starts from n - 1, go all the way back to 0
    // base case: 0 return nums[0]

    // dfs(int i, nums, dp)
    // for each position we can 
    // no, this is not subsequence

    // we probably need if we end here, the largest sum
    // always starting from the start

    // dfs(int i, nums, dp)
    // base, 0 return nums[0]

    // 1, we compare previous largest and 1 and previous largest + 1
    // 2, we comopare previous largest and adding the current or not

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // base case
        int maxSum = nums[0];
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            // If current_subarray is negative, throw it away. Otherwise, keep
            // adding to it.
            currSum = max(0, currSum) + nums[i];
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
        
    }

    // int maxSubArray(vector<int>& nums) {
    //     // Initialize our variables using the first element.
    //     int currentSubarray = nums[0];
    //     int maxSubarray = nums[0];
    //     // Start with the 2nd element since we already used the first one.
    //     for (int i = 1; i < nums.size(); i++) {
    //         // If current_subarray is negative, throw it away. Otherwise, keep
    //         // adding to it.
    //         currentSubarray = max(nums[i], currentSubarray + nums[i]);
    //         maxSubarray = max(maxSubarray, currentSubarray);
    //     }
    //     return maxSubarray;
    // }

};