
class Solution {

public:
    std::vector<int> findCoins(const std::vector<int>& numWays) {
        int n = static_cast<int>(numWays.size());
        std::vector<long long> myWays(n + 1, 0);
        myWays[0] = 1;

        std::vector<int> res;

        for (int i = 1; i <= n; ++i) {
            // -1 because numWays[0] = ways to come up with amount 1
            // If myWays[x] == numWays[x], move on.
            if (myWays[i] == numWays[i - 1]) 
                continue;

            // If myWays[x] + 1 == numWays[x]
            // add that value as a coin in our basket and 
            // update `myWays`, so `myWays[x...n]` accounts for ways with the new coin.
            if (numWays[i - 1] - myWays[i] == 1) {
                res.push_back(i);
                // update myWays
                for (int j = i; j <= n; ++j) {
                    myWays[j] += myWays[j - i];
                }
            // If `myWays[x] + 1 < numWays[x]
            // no solution.
            } else {
                return {};
            }
        }
        return res;
    }


};

