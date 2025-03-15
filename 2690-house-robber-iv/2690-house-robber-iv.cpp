// class Solution {
// public:

//     // dp
//     // what is the subproblem
//     // k is a constraint, is always feasible
//     // target is max the min of the house rob

//     // memorize

//     vector<vector<int>> dp;

//     int dfs(const vector<int>& nums, int currIdx, int k, int currCapacity) {

//         cout << currIdx << " " << k << " " << currCapacity << endl;

//         if (currIdx >= nums.size()) {
//             // when reached the end, we need to rob at least k
//             if (k <= 0)
//                 return currCapacity;
//             else {
//                 // did not meet the requirement
//                 return INT_MAX;
//             }
//         }

//         if (dp[currIdx][k] != -1)
//             return dp[currIdx][k];

//         // for every idx, we can choose rob or not
//         // rob, then we cannot rob the next one, rob the next next one
//         int option1 = dfs(nums, currIdx + 2, k - 1, max(currCapacity, nums[currIdx]));
//         // don't rob
//         int option2 = dfs(nums, currIdx + 1, k, currCapacity);

//         dp[currIdx][k] = min(option1, option2);

//         return dp[currIdx][k];
//     } 

//     int minCapability(vector<int>& nums, int k) {
//         // safe to pass -1 because k at least 1
//         vector<vector<int>>(nums.size(), vector<int>(k + 1, -1));
//         return dfs(nums, 0, k, -1);
//     }
// };


class Solution {
public:

    int minCapability(vector<int>& nums, int k) {
        int minReward = 1;
        int maxReward = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        while (minReward < maxReward) {
            int midReward = (minReward + maxReward) / 2;
            int possibleThefts = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= midReward) {
                    possibleThefts += 1;
                    i++;
                }
            }

            if (possibleThefts >= k) {
                maxReward = midReward;
            } else {
                minReward = midReward + 1;
            }

        }

        return minReward;
    }
};