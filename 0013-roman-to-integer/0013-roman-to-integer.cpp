
// The same principle applies to the number nine, 
// which is written as IX. There are six instances 
// where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.
// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V = 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// Roman numerals are usually written largest to smallest from left to right.
// special case
// IV IX
// XL XC
// CD CM
// invariant
// always written before the large number
// and regularly large to small

// first of all we should create an unordered_map
// we check the next char
// if it's a bigger one
// we know we cannot simply write the current value
// and should apply the subtraction

class Solution {
public:

    const unordered_map<char, int> lookUp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                             {'C', 100}, {'D', 500}, {'M', 1000}};

    int romanToInt(string s) {

        int ans = 0;
        int idx = 0;
        while (idx < s.size()) {
            int currVal = lookUp.at(s[idx]);
            int nextVal = 0;
            if (idx + 1 < s.size())
                nextVal = lookUp.at(s[idx + 1]);
            
            if (nextVal > currVal) {
                ans += nextVal - currVal;
                idx++;
            } else {
                ans += currVal;
            }
            idx++;
        }

        return ans;
    }
};