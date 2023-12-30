class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> aMap;
        for (auto s : words) 
            for (auto c : s)
                aMap[c] += 1;  
        
        for (auto pair : aMap)
            if (pair.second % words.size() != 0)
                return false;
        return true;
        
    }
};