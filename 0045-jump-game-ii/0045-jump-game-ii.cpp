class Solution {
public:
    // maximum length of a forward jump from index i
    // Return the minimum number of jumps to reach index n - 1
    // The test cases are generated such that you can reach index n - 1
    // edge case: nums.size() == 1
    // edge case: nums[0] = 0
    // range for the num in nums?
    // 0 <= 1000
    // nums.size() at least 1
    // we can solve like a dp method
    // dp[n-1] = ans
    // dp: the min step to jump to here
    // dp[0] = 0;
    // we mark the dp[j] as 1 + dp[i] + (0, nums[i])
    // so two loops
    // for (i = 0 < n)
    //     for (k to nums[i])
    //         dp[i+k] = min(dp[i+k], dp[i] + 1)
    // time: O(n^2)
    // space: O(n) for dp array
    // O(n) solution
    //Input: nums = [2,3,1,1,4]
    // Output: 2
    // farthest 0
    // currEnd = 2
    // ans = 0
    int jump(vector<int>& nums) {

        int n = nums.size();
        int farthest = 0;
        int curEnd = 0;
        int ans = 0;
        // 目前跳了 step 次，能覆蓋到的最遠範圍是哪裡？
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == curEnd) {
                // 代表目前這一層掃完了
                // 必須多跳一次
                ans++;
                curEnd = farthest;
                farthest = i;
            }
        }
        return ans;
    }
        
};