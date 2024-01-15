class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loseCnts;
        sort(matches.begin(), matches.end());
        for (auto match : matches) {
            if (loseCnts.find(match[0]) == loseCnts.end())
                loseCnts[match[0]] = 0;
            loseCnts[match[1]]++;
        }
        
        vector<vector<int>> ans(2);
        for (auto cnt : loseCnts) {
            if (cnt.second ==0)
                ans[0].push_back(cnt.first);
            else if (cnt.second == 1)
                ans[1].push_back(cnt.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};