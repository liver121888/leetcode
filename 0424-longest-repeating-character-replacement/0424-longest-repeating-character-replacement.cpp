
// we can do a dp
// dp[i][k] = the longest repeating string can achieve
// s consists of only uppercase English letters.

// base case 
// dp[0][0] = 0
// dp[1][k] = 1

// dp[i][k] = max(if (s[i -1] == s[i]) dp[i-1][k] + 1 
//             else dp[i-1][k-1] + 1)

// s = "ABAB", k = 2
// A
// AB

//    0 1 2
// "" 0 0 0
// A  1 1 1
// B  2
// A
// B


// time: O(n * m)
// space: O(n * m)

// u don't need dp
// u only need freq and sliding window

class Solution {
public:

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0;
        int maxFreq = 0; // 追蹤視窗內出現次數最多的字元頻率
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            // 更新當前視窗內的最大頻率
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // 當「視窗內其他字元數量」大於 k 時，縮小視窗
            while (r - l + 1 - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
                // 注意：這裡不需要手動重新計算新的 maxFreq，
                // 具體原因見下方的「進階冷知識」。
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    
};