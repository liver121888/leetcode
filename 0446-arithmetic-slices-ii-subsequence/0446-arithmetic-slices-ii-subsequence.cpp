// class Solution {
// public:    
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         int res = 0;
//         int diff = 0;
//         vector<unordered_map<int, int>> dp(n);
//         // dp[i][diff] = number of subseq ending at index i, with diff
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 diff = nums[i] - nums[j];
//                 dp[i][diff] += 1 + dp[j][diff];    
//                 res += dp[j][diff];
//             }
//         }
//         return res - (n * (n - 1) / 2);
//     }
// };


#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<unordered_map<int, int>> dp(n);  // Corrected declaration and initialization

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> &currentMap = dp[i];  // Reference to the current map
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];  // Handle potential overflow
                if (diff < INT_MIN || diff > INT_MAX) continue;  // Skip if overflow
                int d = static_cast<int>(diff);
                currentMap[d] += 1 + dp[j][d];
                res += dp[j][d];
            }
        }

        return res;
    }
};