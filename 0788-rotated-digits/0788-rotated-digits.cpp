

// An integer x is a good if after rotating each digit 
// individually by 180 degrees, we get a valid number 
// that is different from x.

// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
// Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

// Example 2:
// Input: n = 1
// Output: 0

// Example 3:
// Input: n = 2
// Output: 1

// brute force
// check n numbers and rotate each number
// O(n * log(n)), because for n we check log_10(n) times

// class Solution {
// public:

//     bool isGood(int i) {

//         int numDigits = 0;
//         int newNum = 0;
//         int n = i;
//         while (n > 0) {
//             numDigits++;
//             n /= 10;
//         }

//         n = i;
//         for (int j = 0; j < numDigits; j++) {
//             int digit = n % 10;
//             n /= 10;
//             if (digit == 3 || digit == 4 || digit == 7)
//                 return false;
//             if (digit == 2)
//                 digit = 5;
//             else if (digit == 5)
//                 digit = 2;

//             if (digit == 6)
//                 digit = 9;
//             else if (digit == 9)
//                 digit = 6;

//             for (int cnt = 0; cnt < j; cnt++)
//                 digit *= 10;
//             newNum += digit;
//         }


//         return n != newNum;
//     }


//     int rotatedDigits(int n) {

//         if (n <= 0)
//             return -1;

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//             if (isGood(i))
//                 ans++;
//         return ans;
//     }
// };

// brute force
// check n numbers and rotate each number
// O(n * log(n)), because for n we check log_10(n) times
// space: O(log(n))
class Solution {
public:
    int rotatedDigits(int n) {
        // Count how many n in [1, N] are good.
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (good(i, false)) 
                ans++;
        return ans;
    }

    // Return true if n is good.
    // The flag is true iff we have an occurrence of 2, 5, 6, 9.
    bool good(int n, bool flag) {
        if (n == 0) 
            return flag;

        // very good idea to use recursion
        int d = n % 10;
        if (d == 3 || d == 4 || d == 7) 
            return false;
        if (d == 0 || d == 1 || d == 8) 
            return good(n / 10, flag);
        return good(n / 10, true);
    }
};