class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> aMap(26, -1);
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (aMap[s[i] - 'a'] != -1)
                ans = max(ans, i - aMap[s[i] - 'a'] - 1);
            else
                aMap[s[i] - 'a'] = i;           
        }
        return ans;
    }
};