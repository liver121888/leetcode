class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> memo(26, s.length() + 1);
        
        for (int i = 0; i < s.length(); i++) {
            if (memo[s[i] - 'a'] == s.length() + 1)
                memo[s[i] - 'a'] = i;
            else
                memo[s[i] - 'a'] = s.length();
        }
        
        int curFirst = s.length();
        for (auto cnt : memo) {
            curFirst = min(cnt, curFirst);
        }

        return curFirst == s.length() ? -1 : curFirst;
    }
};