
// assume ride only have end <= n
// assume starts >=1
// assume no ride have start == end
// assume size of rides can fit in an int

using pii = pair<int,int>;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        vector<vector<pii>> rideStartAt(n);
        for (auto& ride : rides) {
            int s = ride[0], e = ride[1], t = ride[2];
            rideStartAt[s].push_back({e, e - s + t});  // [end, dollar]
        }
        vector<long long> dp(n+1);
        for (int i = n-1; i >= 1; --i) {
            // if there's a ride
            for (auto& [e, d] : rideStartAt[i]) {
                dp[i] = max(dp[i], dp[e] + d);
            }
            // whether there is a ride, we pass on the dp
            dp[i] = max(dp[i], dp[i + 1]);
        }

        return dp[1];
        
    }
};