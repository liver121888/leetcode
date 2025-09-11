class Solution {
public:
    string sortVowels(string s) {
        
        // uppercase at front
        unordered_map<char, int> aMap = {{'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}, {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        vector<char> keys = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    
        for (int i = 0; i < s.length(); i++) {
            if (aMap.find(s[i]) != aMap.end()) {
                aMap[s[i]]++;
            }
        }

        string ans = "";
        int vowelIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            auto curChar = s[i];
            if (aMap.find(curChar) != aMap.end()) {
                while (!aMap[keys[vowelIdx]]) {
                    vowelIdx++;
                }
                curChar = keys[vowelIdx];
                aMap[keys[vowelIdx]]--;
            }
            
            ans += curChar;

        }
        return ans;
    }
};