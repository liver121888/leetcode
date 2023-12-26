#include <vector>
#include <unordered_map>

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numRollsToTarget(int d, int f, int target) {
        // Memoization table
        std::unordered_map<std::string, int> memo;
        return helper(d, f, target, memo);
    }

private:
    int helper(int d, int f, int target, std::unordered_map<std::string, int>& memo) {
        // Base cases
        if (d == 0 && target == 0) {
            return 1;
        }
        if (d == 0 || target <= 0) {
            return 0;
        }

        // Check if the result is already memoized
        std::string key = std::to_string(d) + "_" + std::to_string(target);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int ways = 0;
        for (int i = 1; i <= f; ++i) {
            ways = (ways + helper(d - 1, f, target - i, memo)) % MOD;
        }

        // Memoize the result
        memo[key] = ways;
        return ways;
    }
};
