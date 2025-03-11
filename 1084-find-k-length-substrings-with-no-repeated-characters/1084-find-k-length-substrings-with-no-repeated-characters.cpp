class Solution {
public:

    bool checkValid(const vector<int>& freq) {
        for (auto f : freq) {
            if (f > 1)
                return false;
        }
        return true;
    }

    int numKLenSubstrNoRepeats(string s, int k) {

        // of len k -> sliding window
        // freq

        // deal with edge case 
        // if (k > s.length())
        //     return 0;

        auto freq = vector<int>(26);
        int l = 0; int result = 0;
        for (int r = 0; r < s.length(); r++) {

            freq[s[r] - 'a']++;

            // retract
            if (r - l + 1 > k) {
                freq[s[l] - 'a']--;
                l++;
            }

            if (checkValid(freq) && r - l + 1 == k) {
                result++;
                // cout << "l " << l << " r " << r << " result " << result << endl;
            }

            // expand
        }
        return result;
    }
};