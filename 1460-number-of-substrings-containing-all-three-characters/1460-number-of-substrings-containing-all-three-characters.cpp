class Solution {
public:
    bool valid(const vector<int>& cnts) {
        for (auto cnt : cnts)
            if (cnt < 1)
                return false;
        return true;
    }

    int numberOfSubstrings(string s) {

        // a, b, c
        vector<int> cnts = {0, 0, 0};

        // vector<vector<int>> nextChar = vector<vector<int>>(3, vector<int>(s.length()));
        // vector<int> nextCnts = {s.length() - 1, s.length() - 1, s.length() - 1};

        // for (int i = s.length() - 1; i >= 0; i--) {
        //     auto charIdx = s[i] - 'a'
        //     nextChar[charIdx][i] = nextCnts[charIdx];

        //     nextCnts[charIdx] = i
        // }

        int n = s.length();
        int l = 0;
        int result = 0;
        for (int r = 0; r < n; r++) {
            cnts[s[r] - 'a']++;
            while (valid(cnts)) {
                // this valid thinking is important!
                result += n - r;
                cnts[s[l] - 'a']--;
                l++;
            }

        }
        return result;        
    }
    // l 0, r 0, result 0, cnts 0 0 0
    // l 0 r 1 result 0 cnts 1 0 0 -> not valid
    // l 0 r 2 cnts 1 1 1 -> valid result = 1, cannot retract
    // l 0 r 3 cnts 2 1 1 -> valid result = 2, retract result = 3
    // l 1 r 4

};