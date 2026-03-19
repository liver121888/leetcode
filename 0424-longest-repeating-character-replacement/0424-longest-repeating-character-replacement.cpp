
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
    // 最重要公式
    // windowSize−maxFrequency<=k
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

    // 進階冷知識：為什麼縮小 l 時不需要更新 maxFreq？
    // 在上面的代碼中，當 l++ 時，freq[s[l]] 減少了，
    // 理論上 maxFreq 可能會變小。但為什麼我們不重新掃描 freq 數組來找新的最大值呢？

    // 因為：
    // 我們的目標是找 「最大」 的視窗。
    // 只有當 maxFreq 變得 「更大」 時，我們才有可能得到比目前 ans 更長的可行視窗。
    // 如果當前的 maxFreq 減小了，視窗只會縮小或保持不變，不會產生新的紀錄。
    // 所以，maxFreq 其實可以看作是 「歷史上曾出現過的最大頻率」。




};