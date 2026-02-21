// s consists of English letters, digits, symbols and spaces.
// brute-force: every substring and see if they have repeating characters
// longest possbile is the whole string, we, check for the left 
// and right ptr, find the largest nuber in the string and minus it out by one
// so we get the longest substring
// eg abcabcbb
// a 2 b 4 c 2
// l = 0; r = size - 1
// a 1 b 1 c 1 -> 3

// "bbbbb"
// b 5
// b 1 -> 1

// "pwwkew"
// p 1 w 3 k 1 e 1
// p 1 w 2 k 1 e 1 -> if we shrink the back
// pw -> 2 wrong ans

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        unordered_map<char, int> freq;
        int ans = 0;
        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                // shrink
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};