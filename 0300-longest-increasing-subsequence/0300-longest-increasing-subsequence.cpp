class Solution {
public:
    int dfs(const vector<int>& nums, vector<int>& memo, int i) {
        // Base case: 雖然你寫了 if(i==0) return 1
        // 但其實下面的 loop 跑不進去時，預設回傳 1 也是對的 (自己就是長度1)
        
        if (memo[i] != 0) return memo[i];

        int maxLen = 1; // 至少包含自己
        
        // 往前找所有可能接在後面的元素
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                maxLen = max(maxLen, dfs(nums, memo, j) + 1);
            }
        }

        memo[i] = maxLen;
        return maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> memo(n, 0);
        
        // 修正點：LIS 可能結束在任何位置，所以要遍歷所有位置
        int globalMax = 1;
        for (int i = 0; i < n; i++) {
            globalMax = max(globalMax, dfs(nums, memo, i));
        }
        
        return globalMax;
    }
};