class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCnts(26, 0);
        for (auto c : s) {
            sCnts[c - 'a']++;
        }
        
        for (auto c : t) {
            sCnts[c - 'a']--;
        }
        
        int res = 0;
        for (auto cnt : sCnts) {
            if (cnt > 0)
                res += cnt;
        }
        return res;
        
    }
};