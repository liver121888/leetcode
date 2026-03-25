
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

// class Solution {
// public:

//     const unordered_map<char, int> lookUp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
//                                              {'C', 100}, {'D', 500}, {'M', 1000}};

//     int romanToInt(string s) {

//         int ans = 0;
//         int idx = 0;
//         while (idx < s.size()) {
//             int currVal = lookUp.at(s[idx]);
//             int nextVal = 0;
//             if (idx + 1 < s.size())
//                 nextVal = lookUp.at(s[idx + 1]);
            
//             if (nextVal > currVal) {
//                 ans += nextVal - currVal;
//                 idx++;
//             } else {
//                 ans += currVal;
//             }
//             idx++;
//         }

//         return ans;
//     }
// };

// 簡潔作法
// 不用特判看兩個
// 就是一個一個看如果下一個比現在的大
// 把現在的變成負數
class Solution {
public:
    int value(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000;
    }

    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int curr = value(s[i]);

            if (i + 1 < s.size() && curr < value(s[i + 1])) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }

        return ans;
    }
};