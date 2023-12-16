class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> aMap;
        for (char c : s)
            aMap[c] += 1;
        for (char c : t)
            aMap[c] -= 1;
        
        for (auto& pair : aMap)
            if (pair.second != 0)
                return false;
        
        return true;        
    }
};