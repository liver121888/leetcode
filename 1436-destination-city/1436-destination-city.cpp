class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> aSet;
        for (auto path : paths)
            aSet.insert(path[0]);
        
        for (auto path : paths)
            if (aSet.find(path[1]) == aSet.end())
                return path[1];    
        
        return "";
    }
};