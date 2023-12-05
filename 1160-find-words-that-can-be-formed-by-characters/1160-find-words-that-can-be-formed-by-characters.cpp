class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> cnts;
        unordered_map<char, int> curCnts;
        
        int ans = 0;
        for (auto c : chars) {
            cnts[c] += 1;
        }
        
        int length = 0;
        for (auto word : words) {
            length = word.length();
            for (auto c : word) {
                if (cnts.find(c) == cnts.end()) {
                    length = 0;
                    break;
                } 
                curCnts[c] += 1;
                if (curCnts[c] > cnts[c]) {
                    length = 0;
                    break;
                }
            }
            ans += length;
            curCnts.clear();
        }
        return ans;
    }
};