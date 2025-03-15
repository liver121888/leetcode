class Solution {
public:
    bool canPermutePalindrome(string s) {

        vector<int> cnts(26, 0);

        for (auto c : s) {
            cnts[c - 'a'] += 1;
        }

        int numOdd = 0;
        for (auto cnt : cnts) {
            if (cnt % 2 == 1)
                numOdd += 1;
        }
        return (numOdd <= 1) ? true : false;
    }
};