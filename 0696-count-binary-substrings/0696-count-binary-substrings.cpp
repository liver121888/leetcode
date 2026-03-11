
// equal number of consecutive
// distinct groups of 0 and 1
// count how many times it occurs
// Input: s = "00110011"
// Output: 6
// "0011": 2
// 01: 2
// "1100",: 1
// 10: 1

// s = "10101"

// we can use a stack, to get the non-continuous part
// a 1 can pair up with one 0
// "000111"
// 3
// "11100"
// "00011100"


// len 2:
// either 01 or 10
// we traverse the string to find it
// len 4:
// len 6:
// O(n^2)

// are grouped consecutively.
// 00110011
// 12223444
// 00122234

// we traverse the string
// if empty, push
// no matter 0 or 1 we push it in
// if top != curr
// pop once ans +1
// if equal we push

// "00110"

// we collect how many times current streak is going
// if we break the streak, keep accmulating and see
// the new streak with the current streak
// if the new streak > current streak
// add current streak but keep the new streak

// "00110011"
// 0 2 
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, curr = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] != s[i]) {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        }
        return ans += min(prev, curr);
    }
};