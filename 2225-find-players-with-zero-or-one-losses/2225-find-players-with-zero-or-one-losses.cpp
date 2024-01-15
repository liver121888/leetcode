class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loseCnts;
        // sort(matches.begin(), matches.end());
        for (auto match : matches) {
            loseCnts[match[1]]++;
        }
        
        vector<int> noLose;
        vector<int> oneLose;
        
        for(int i = 0; i < matches.size(); i++)
        {
           int winner = matches[i][0];
           int looser = matches[i][1];
           if(loseCnts.find(winner) == loseCnts.end()) {
               noLose.push_back(winner);
               loseCnts[winner] = 2;
           }
           if(loseCnts[looser] == 1)
               oneLose.push_back(looser);
        }
        
        // for (auto cnt : loseCnts) {
        //     if (cnt.second == 0)
        //         noLose.push_back(cnt.first);
        //     else if (cnt.second == 1)
        //         oneLose.push_back(cnt.first);
        // }
        sort(noLose.begin(), noLose.end());
        sort(oneLose.begin(), oneLose.end());
        return {noLose, oneLose};
    }
};