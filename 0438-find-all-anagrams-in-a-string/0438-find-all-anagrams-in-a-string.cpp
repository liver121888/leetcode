class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pCnts(26, 0);
        for (auto c : p) {
            pCnts[c - 'a']++;
        }
        
        vector<int> sCnts(26, 0);
        vector<int> ans;
        int left  = 0;
        bool valid = true;
        for (int right = 0; right < s.length(); right++) {
            
            //contract
            if (right - left + 1 > p.length()) {
                sCnts[s[left] - 'a']--;
                left++;
            }
            
            sCnts[s[right] - 'a']++;
            valid = true;
            for (int i = 0; i < pCnts.size(); i ++)
                if (sCnts[i] != pCnts[i]) {
                    valid = false;
                    break;
                }
            if (valid)
                ans.push_back(left);            
            
        }
        return ans;        
    }
};