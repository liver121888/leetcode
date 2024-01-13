class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCnts(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            sCnts[t[i] - 'a']++;
            sCnts[s[i] - 'a']--;
        }

        int res = 0;
        for (auto cnt : sCnts) {
            if (cnt > 0)
                res += cnt;
        }
        return res;
    }
};