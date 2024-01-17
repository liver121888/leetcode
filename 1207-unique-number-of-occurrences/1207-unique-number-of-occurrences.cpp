class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> aMap;
        for (auto n : arr) {
            aMap[n]++;
        }
        
        unordered_set<int> aTable;
        for (auto cnt : aMap) {
            if (aTable.find(cnt.second) == aTable.end())
                aTable.insert(cnt.second);
            else
                return false;
        }
        return true;        
    }
};