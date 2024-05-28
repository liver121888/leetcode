class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int curMaxLength = 0;
        int curCost = 0;
        for (int r = 0; r < s.length(); r++) {
            // expand
            curCost += abs(s[r] - t[r]);
            
            while (curCost > maxCost) {
                // contract
                curCost -= abs(s[l] - t[l]);
                l += 1;
            }
            
            if (r - l + 1 > curMaxLength) {
                curMaxLength = r - l + 1;
            }
        }
        return curMaxLength;
        
    }
};