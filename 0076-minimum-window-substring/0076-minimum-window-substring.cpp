// can we use sliding window on this?
// is there monotonic
// so we expanding until we have all the from t
// if that ever occurs, we shrink l
// see the minimum
class Solution {
public:

    // s and t consist of uppercase and lowercase English letters.
    // time: O(n * 52 + O(n))
    // space: O(t)

    bool isMatch(const unordered_map<char,int>& currFreq, const unordered_map<char,int>& freq) {

        for (const auto& [c, cnt] : freq) {
            // if there is still char not matched
            // we can over match
            if (currFreq.find(c) == currFreq.end())
                return false;
            if (currFreq.at(c) < cnt)
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (const auto& c : t) {
            freq[c]++;
        }
        // we need substring 
        // so we need to save idx

        int l = 0;
        int minLen = INT_MAX/2;
        int lResult = INT_MAX/2;
        int rResult = INT_MAX/2;
        unordered_map<char, int> currFreq;

        for (int r = 0; r < s.size(); r++) {
            currFreq[s[r]]++;
            // cout << r << endl;
            // actually don't have to check the whole window, 
            // only need to check the changed one
            while (isMatch(currFreq, freq)) {

                // record ans;
                if (r - l + 1 < minLen) {
                    lResult = l;
                    rResult = r;
                    minLen = r - l + 1;
                }
                
                // shrink
                currFreq[s[l]]--;
                l++;
            }
        }
        
        return lResult == INT_MAX/2 ? "" : s.substr(lResult, rResult - lResult + 1);
    }
};
