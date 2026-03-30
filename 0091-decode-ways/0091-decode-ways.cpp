// this is a dp problem because the way we do will affect the later part
// in each position, we can choose to add the current num to decode
// or choose not to
// in each dp we will store the num of ways to decode
// and we build up the ans till the end
// a couple situation
// if curr is able to be decode
// decode itself +1 method
// if curr can be combined with the prev
// decode with the prev +1

// we move on to the next index
// "226"
// 2 -> 1
// dp[0] = 1
// // 22
// curr = 1 + 1 = 2
// // 226
// curr = 1 + 1 = 2

// dp[i] = max(dp[i-1], dp[i-2] 
// time complexity: O(n), we visit each index and calculate once
// space complexity: O(n), we store dp array

// dp = number of ways that we can decode up until here

// "12"
//    decode as one number
// dp[i] = + dp[i-2] if double decode is possible + dp[i-1] if single decode is possible
// dp[i] = 前 i 個字元（s[0..i-1]）的解碼方法數
//  s = "226"

// dp[0] = 1
// dp[1] = dp[-1] + curr == 2 1 = 2
// dp[2] = dp[0] + dp[1] = 3

class Solution {
public:

    // 10
    // 1 

    int numDecodings(string s) {

        int n = s.size();
        // handle leading zero case
        if (n == 0 || s[0] == '0') 
            return 0;
        
        // if (n == 1)
        //     return s[0] == '0' ? 0 : 1;
        // if (n == 2) {
        //     int first = s[0] == '0' ? 0 : 1;
        //     int second = s[1] == '0' ? 0 : 1;
        //     return first + second;
        // }


        vector<int> dp(n+1, 0);
        // dp[0] = 1：空字串有 1 種方式
        dp[0] = 1;
        // dp[1] -> s[0], def not zero because we already
        // reject on the top, so we put 1
        dp[1] = 1;
        
        // dp[1] = s[0] == '0' ? 0 : 1;

        // 1 1 2

        // cout << dp[0] << endl;

        // 10

        for (int i = 2; i <= n; i++) {
            // single decode is possible
            // single decode: 看目前這個字元，不是前一個
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            int two_digit = stoi(s.substr(i - 2, 2));
            if (two_digit >= 10 && two_digit <= 26) {
                dp[i] += dp[i - 2];
            }

            // cout << dp[i] << endl;

        }
        return dp[n];
    }
};