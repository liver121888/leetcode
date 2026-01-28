// class Solution {
// public:
//     int dfs(const vector<int>& nums, vector<int>& memo, int i) {
//         // Base case: 雖然你寫了 if(i==0) return 1
//         // 但其實下面的 loop 跑不進去時，預設回傳 1 也是對的 (自己就是長度1)
        
//         if (memo[i] != 0) return memo[i];

//         int maxLen = 1; // 至少包含自己
        
//         // 往前找所有可能接在後面的元素
//         for (int j = 0; j < i; j++) {
//             if (nums[i] > nums[j]) {
//                 maxLen = max(maxLen, dfs(nums, memo, j) + 1);
//             }
//         }

//         memo[i] = maxLen;
//         return maxLen;
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
        
//         vector<int> memo(n, 0);
        
//         // 修正點：LIS 可能結束在任何位置，所以要遍歷所有位置
//         int globalMax = 1;
//         for (int i = 0; i < n; i++) {
//             globalMax = max(globalMax, dfs(nums, memo, i));
//         }
        
//         return globalMax;
//     }
// };



// bottom-up
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;

//         // dp[i] 初始化為 1，因為每個數字本身至少是一個長度為 1 的子序列
//         vector<int> dp(n, 1);
//         int maxAns = 1;

//         // 外層迴圈：計算每個位置 i 的 dp 值
//         for (int i = 1; i < n; i++) {
//             // 內層迴圈：檢查 i 之前的所有位置 j
//             for (int j = 0; j < i; j++) {
//                 // 如果 nums[i] 能接在 nums[j] 後面
//                 if (nums[i] > nums[j]) {
//                     // 嘗試更新 dp[i]
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             // 隨時更新全域最大值
//             maxAns = max(maxAns, dp[i]);
//         }

//         return maxAns;
//     }
// };


// binary serach to build the subarray
class Solution {

public:


    // find the first >= target
    // if we found equal, we want to move to the left because 
    // we want to find the first >= target
    // if we have [2 2 2] find 2
    // r go back to -1, we return l;
    int binarySearch(const vector<int>& subseq, int target) {

        int l = 0, r = subseq.size()-1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if (subseq[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {

        vector<int> subseq;
        subseq.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > subseq[subseq.size()-1])
                subseq.push_back(num);
            else {
                int j = binarySearch(subseq, num);
                subseq[j] = num;
            }
        }

        return subseq.size();

    }


};