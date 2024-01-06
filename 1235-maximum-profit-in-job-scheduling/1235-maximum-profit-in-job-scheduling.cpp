#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int n;
    std::vector<int> dp;  // Use a vector instead of a pointer

    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        n = startTime.size();

        // Create an index array for sorting
        std::vector<int> index(n);
        std::iota(index.begin(), index.end(), 0);

        // Sort index based on the values in vector1
        std::sort(index.begin(), index.end(), [&](int a, int b) {
            return startTime[a] < startTime[b];
        });

        // Rearrange vectors based on the sorted order
        std::vector<int> sortedStartTime(n);
        std::vector<int> sortedEndTime(n);
        std::vector<int> sortedProfit(n);

        for (int i = 0; i < n; i++) {
            sortedStartTime[i] = startTime[index[i]];
            sortedEndTime[i] = endTime[index[i]];
            sortedProfit[i] = profit[index[i]];
        }

        // Initialize dp vector with size n + 1, all elements set to -1
        dp.assign(n + 1, -1);

        return dfs(0, sortedStartTime, sortedEndTime, sortedProfit);
    }

    int dfs(int i, std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        // base case
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int res = dfs(i + 1, startTime, endTime, profit);

        auto it = std::lower_bound(startTime.begin() + i, startTime.end(), endTime[i]);

        int j = std::distance(startTime.begin(), it);
        res = std::max(res, profit[i] + dfs(j, startTime, endTime, profit));

        return dp[i] = res;
    }
};
