// subset the array
// sequence does not matter
// subset may have variable length
// we can sum the entire array first
// then we collect subset 1 to see what's the rest
// if the rest is equal to subset 1 we know it's possible
// subset problem is a dp naturally

// in every position we have two options
// 1. select the current element and add to subset
// 2. don't

// time complexity: O(2^n)
// space complexity: O(N) for recursive calls

// let's try recursive with memo first
// ok we have the recursive part, now how can we memo this
// what are some repeated question here?
// totalSum - currentSum == currentSum
// we are actually looking for totalSum == 2 * currentSum

class Solution {
public:

    // TLE, this solution does no capture the top-down dp idea
    // it just backtrack to the end of the array
    // 絕對算是 Backtracking（回溯法）的一種形式，更精確地說，它是暴力遞迴（Brute Force Recursion）。

    // int totalSum = 0;
    // int n = 0;

    // bool dfs(const vector<int>& nums, int i, int currentSum) {

    //     if (i >= n)
    //         return false;

    //     if (totalSum - currentSum == currentSum)
    //         return true;

    //     // two options

    //     // 1. add the current element
    //     bool successFirst = dfs(nums, i+1, currentSum+nums[i]);

    //     // 2. don't add the current element
    //     bool successSecond = dfs(nums, i+1, currentSum);

    //     return successFirst || successSecond;

    // }

    // bool canPartition(vector<int>& nums) {
        
    //     totalSum = accumulate(nums.begin(), nums.end(), 0);
    //     if (totalSum % 2 != 0)
    //         return false;
    //     n = nums.size();
    //     // cout << totalSum << endl;
    //     return dfs(nums, 0, 0);

    // }


    // Top-down DP
    // Time: O(mn)
    // Space: O(mn)
    // bool canPartition(vector<int> &nums) {
    //     int totalSum = 0;
    //     for (int num : nums) {
    //         totalSum += num;
    //     }
        
    //     if (totalSum % 2 != 0) return false;
        
    //     int subSetSum = totalSum / 2;
    //     int n = nums.size();
        
    //     // 修改點 1: 使用 int 矩陣，並初始化為 -1
    //     vector<vector<int>> memo(n + 1, vector<int>(subSetSum + 1, -1));
        
    //     // Top-down dfs with memo
    //     return dfs(nums, n - 1, subSetSum, memo);
    // }

    // // 修改點 2: memo 的型別改為 vector<vector<int>>
    // bool dfs(vector<int> &nums, int n, int subSetSum, vector<vector<int>> &memo) {
    //     if (subSetSum == 0) return true;
    //     if (n < 0 || subSetSum < 0) return false; // 注意這裡的 base case 修正
        
    //     // 修改點 3: 檢查是否為 -1
    //     if (memo[n][subSetSum] != -1) {
    //         return memo[n][subSetSum]; // int 會自動轉型為 bool (1->true, 0->false)
    //     }
        
    //     bool result = dfs(nums, n - 1, subSetSum - nums[n], memo) || 
    //                 dfs(nums, n - 1, subSetSum, memo);
                    
    //     // 修改點 4: 儲存時，bool 會自動轉為 1 或 0
    //     return memo[n][subSetSum] = result;
    // }


    // bottom-up
    // bool canPartition(vector<int> &nums) {
    //     int totalSum = 0;
    //     // find sum of all array elements
    //     for (int num : nums) {
    //         totalSum += num;
    //     }
    //     // if totalSum is odd, it cannot be partitioned into equal sum subset
    //     if (totalSum % 2 != 0) return false;
    //     int subSetSum = totalSum / 2;
    //     int n = nums.size();
    //     bool dp[n + 1][subSetSum + 1];
    //     memset(dp, 0, (n + 1) * (subSetSum + 1) * sizeof(bool));
    //     dp[0][0] = true;
    //     for (int i = 1; i <= n; i++) {
    //         int curr = nums[i - 1];
    //         for (int j = 0; j <= subSetSum; j++) {
    //             if (j < curr)
    //                 dp[i][j] = dp[i - 1][j];
    //             else
    //                 dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - curr]);
    //         }
    //     }
    //     return dp[n][subSetSum];
    // }

    // the ans
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;

        if (sum % 2 != 0) return false;


        int target = sum / 2;

        // 其實這個 1D DP 是從 2D DP 壓縮來的。

        // 本來可以定義：

        // dp[k][i]

        // 表示：

        // 前 k 個數字能不能湊出和 i

        // 那轉移會是：

        // dp[k][i]=dp[k−1][i]∨dp[k−1][i−nums[k−1]]

        // 意思：

        // 不選第 k 個數
        // 或選第 k 個數



        vector<bool> dp(target + 1, false);
        // dp[i] 表示：
        // 目前處理到某些數字時，能不能選出一部分數，使它們的和剛好等於 i。
        dp[0] = true;


        // 意思是：
        // 要湊出 i，有兩種可能：
        // 情況 1：不選 num
        // 那如果原本 dp[i] 就是 true，現在仍然可以是 true
        // 情況 2：選 num
        // 那你前面必須先能湊出 i-num

        // 如果正著跑：
        // for (int i = num; i <= target; i++)
        // 那同一個 num 可能會被重複使用多次。
        // 變成coin change ii
        // 這就變成 完全背包 了，不是這題要的 0/1 背包。
        // 這題每個數只能用一次，所以要倒著更新。

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }



};