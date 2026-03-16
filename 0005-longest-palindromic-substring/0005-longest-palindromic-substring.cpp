class Solution {
public:

    // we can list all the substring
    // call isPaliiondrome
    // O(n*n*n) -> O(n^3)
    // i j to get subtring -> O(n^2)
    // O(n) on checking palindrome

    // left pointer and a right pointer
    // starting from the back and the front
    // "babad"

    // How can we reuse a previously computed 
    // palindrome to compute a larger palindrome?

    // If “aba” is a palindrome, is “xabax” a palindrome? 
    // Similarly is “xabay” a palindrome?

    // i start ends with j's string
    // is it palindrome or not
    // dp[i][j] = s[i] == s[j] && dp[i+1][j-1]
    // dp[i][i] = true
    // 長度 2 的 palindrome 條件是什麼？

    // 我不直接給你 code，你先試著回答：
    // dp[i][j] 要表示什麼？
    // s[i...j] 是 palindrome 的條件是什麼？
    // base case 有哪些？
    // 為什麼遍歷順序不能亂？
    // 找到 palindrome 後，要怎麼更新最長答案？

    string longestPalindrome(string s) {

        int n = s.size();
        if (n == 0) 
            return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // 長度 1 一定是 palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // "cbbd"
        // [10
            //  11
            //   10
            //    1]

        // offset = j - i
        for (int offset = 1; offset < n; offset++) {
            for (int i = 0; i + offset < n; i++) {
                int j = i + offset;

                // 開頭與結尾必須一樣，不一樣的話直接false
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // 長度 2 或 3，只要頭尾一樣就成立
                    if (offset <= 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // OFFSET+1 = len
                if (dp[i][j] && offset + 1 > maxLen) {
                    start = i;
                    maxLen = offset + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }


};