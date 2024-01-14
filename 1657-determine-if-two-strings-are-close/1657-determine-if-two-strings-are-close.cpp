class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> cnts1(26, 0);
        for (auto c : word1) {
            cnts1[c - 'a']++;
        }
        vector<int> cnts2(26, 0);
        for (auto c : word2) {
            if (cnts1[c - 'a'] == 0)
                return false;
            cnts2[c - 'a']++;
        }
        
        sort(cnts1.begin(), cnts1.end());
        sort(cnts2.begin(), cnts2.end());
        
        return cnts1 == cnts2;
    }
};