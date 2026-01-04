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

    // TLE

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



    bool canPartition(vector<int> &nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 != 0) return false;
        
        int subSetSum = totalSum / 2;
        int n = nums.size();
        
        // 修改點 1: 使用 int 矩陣，並初始化為 -1
        vector<vector<int>> memo(n + 1, vector<int>(subSetSum + 1, -1));
        
        return dfs(nums, n - 1, subSetSum, memo);
    }

    // 修改點 2: memo 的型別改為 vector<vector<int>>
    bool dfs(vector<int> &nums, int n, int subSetSum, vector<vector<int>> &memo) {
        if (subSetSum == 0) return true;
        if (n < 0 || subSetSum < 0) return false; // 注意這裡的 base case 修正
        
        // 修改點 3: 檢查是否為 -1
        if (memo[n][subSetSum] != -1) {
            return memo[n][subSetSum]; // int 會自動轉型為 bool (1->true, 0->false)
        }
        
        bool result = dfs(nums, n - 1, subSetSum - nums[n], memo) || 
                    dfs(nums, n - 1, subSetSum, memo);
                    
        // 修改點 4: 儲存時，bool 會自動轉為 1 或 0
        return memo[n][subSetSum] = result;
    }

};