class Solution {
public:

    // 1 <= chars.length <= 2000
    // chars[i] is a lowercase English letter, 
    // uppercase English letter, digit, or symbol.
    // uses only constant extra space.
    // []
    // we can use a char to save the currChar and keep the 
    // current streak
    // if not the same char anymore
    // time: O(n)
    // O(1) space

    // ["a","a","b","b","c","c","c"]
    int compress(vector<char>& chars) {

        int n = chars.size();
        if (n <= 1)
            return n;

        // we need a two pointers method
        int writePtr = 0, r = 1;
        int currStreak = 1;
        while (r < n) {
            if (chars[r - 1] == chars[r]) {
                currStreak++;
            } else {
                chars[writePtr] = chars[r - 1];
                writePtr++;
                if (currStreak != 1) {
                    string streakStr = to_string(currStreak);
                    for (int k = 0; k < streakStr.length(); k++) {
                        chars[writePtr] = streakStr[k];
                        writePtr++;
                    }
                }
                currStreak = 1;
            }
            r++;
        }

        // last one streak
        // cout << r - 1 << endl;
        chars[writePtr]  = chars[r - 1];
        writePtr++;
        if (currStreak != 1) {
            string streakStr = to_string(currStreak);
            for (int k = 0; k < streakStr.length(); k++) {
                chars[writePtr] = streakStr[k];
                writePtr++;
            }
        }

        // cout << writePtr;
        chars.resize(writePtr);
        return writePtr;
    }
};