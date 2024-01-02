class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLen = 0;
        int l{}; int r{};
        for (int i = 0; i < s.length(); i++) {
            l = i;
            r = i;
            // odd length
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                }
                l -= 1;
                r += 1;
            }
            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    ans = s.substr(l, r - l + 1);
                } 
                l -= 1;
                r += 1;
            }
            
        }
        
        return ans;
    }
};