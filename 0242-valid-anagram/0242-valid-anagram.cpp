// vector or unordered_map to count
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        vector<int> cnts(26);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            cnts[s[i] - 'a']++;
            cnts[t[i] - 'a']--;
        }

        for (int i = 0; i < cnts.size(); i++) {
            if (cnts[i] != 0)
                return false;
        }
        return true;
    }
};