class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int ans{};  
        int i{};
        int j{};
        
        while(i < n && j < m) {
            if (s[j] >= g[i]) {
                ans++;
                j++;
                i++;
            } else {
                j++;
            }                
        }
        return ans;
    }
};