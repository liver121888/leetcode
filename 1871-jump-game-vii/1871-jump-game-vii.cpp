
// dynamic programming problem
// reach index s.length - 1 in s, or false otherwise.
// some base case
// s[s.size()-1] == 1 -> return false
// s[0] is always '0'
// 

// create dp array
// dp[i] can reach -> time: O(n), space: O(n)
// return dp[0]
// base case: true for dp[n-1]

// what if we use dsu
// O(n*k)





class Solution {
public:

    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (n == 0 || s[n-1] == '1')
            return false;
        if (n == 1)
            return true;

        vector<bool> dp(n, false);
        vector<int> pre(n, 0);
        dp[0] = true;

        for (int i = 0; i < minJump; ++i) {
            pre[i] = 1;
        }

        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                dp[i] = (total != 0);
            }
            pre[i] = pre[i - 1] + dp[i];
        }
        return dp[n - 1];
    }


    // O(m * k), where k is the jump range
    // k worst to be n, so O(n^2)
    // bool canReach(string s, int minJump, int maxJump) {
    //     int n = s.size();
    //     if (n == 0 || s[n-1] == '1')
    //         return false;
    //     if (n == 1)
    //         return true;

    //     vector<bool> dp(n, false);
    //     dp[n-1] = true;

    //     for (int i = n - 2; i >= 0; --i) {
    //         if (s[i] != '1') {
    //             for (int k = maxJump; k >= minJump ; k--) {
    //                 if (i + k < n && s[i+k] != '1')
    //                     dp[i] = dp[i] || dp[i + k];
    //             }
    //         }
    //     }
    //     return dp[0];
    // }
};