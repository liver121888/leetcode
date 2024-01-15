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
        
        vector<int> noLose;
        vector<int> oneLose;
        for (auto cnt : loseCnts) {
            if (cnt.second ==0)
                noLose.push_back(cnt.first);
            else if (cnt.second == 1)
                oneLose.push_back(cnt.first);
        }
        sort(noLose.begin(), noLose.end());
        sort(oneLose.begin(), oneLose.end());
        return {noLose, oneLose};
    }
};