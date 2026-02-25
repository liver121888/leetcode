// Input: s = "aa", p = "a"
// Input: s = "aa", p = "a*"
// Input: s = "ab", p = ".*"
// Input: s = "ab", p = ".*."
// * -> 0 - INT_MAX, set to 1
// Input: s = "ab", p = ".*.."
// * -> 0
// Input: s = "ab", p = ".*..."
// not match

// encode the string s
// string p
//  s = "aa", "a2"
// s = "abbbcccddddddhijk" -> s = "a1b3c3d6h1i1j1k1"
// s = "bbbcccddddddhijk" -> s = "b3c3d6h1i1j1k1"
// p = "a*bbbccdd..jk" -> p= "a*b3c2d2.1.1j1k1"

// encode(string) -> string
// compare(string, string) returen true false

// complexity O(n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    // Step 1：先看現在字元能不能 match
    // Step 2：看 pattern[j+1] 是不是 *
    // 情況 A：沒有 *，只能「吃一個字元」
    // 情況 B：有 *
    // 有兩種選擇：
    // 1. 把 x* 當成 0 次 match(i, j+2)
    // 2. 用 1 次以上，前提是first_match && match(i+1, j)
    // 所以dp
    
    bool isMatch(string text, string pattern) {
        int n = (int)text.size();
        int m = (int)pattern.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // 從後面match回來
        // base case: 代表兩個都走到尾巴：空字串 match 空 pattern
        dp[n][m] = true;

        for (int i = n; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {

                bool first_match = (i < n) &&
                    (pattern[j] == text[i] || pattern[j] == '.');

                if (j + 1 < m && pattern[j + 1] == '*') {
                    // 1) 用 0 次：跳過 "x*"
                    // 2) 用 >=1 次：first_match 且 text 往前吃一個，
                    // 但 pattern 留在 j (因為還能繼續用 x*)
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};