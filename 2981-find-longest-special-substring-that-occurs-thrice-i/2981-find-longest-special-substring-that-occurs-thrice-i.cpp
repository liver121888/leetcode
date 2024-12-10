class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> cnts;
        for (int start = 0; start < s.length(); start++) {
            string curString;
            for (int end = start; end < s.length(); end++) {
                if (curString.empty() or curString.back() == s[end]) {
                    curString.push_back(s[end]);
                    cnts[curString]++;
                } else {
                    break;
                }
            }
        }
        
        int ans = -1;
        for (auto i : cnts) {
            // cout << i.first << " " << i.second << endl;
            string str = i.first;
            if (i.second >= 3 && (int)str.length() > ans) {
                ans = str.length();
            }
        }
        
        return ans;
        
    }
};