
// Follow up: Could you solve it without converting the integer to a string?
// isPalindrome
// convert to string and traverse
// O(n), where n is the digits that x has
// we can keep divided by 10
// save a vector


// -121
// 121
// 121/10 -> 12
// 121 % 10 -> 1
// 121/100 -> 1

// class Solution {
// public:
//     bool isPalindrome(int x) {

//         if (x < 0)
//             return false;

//         vector<int> v;
//         while (x) {
//             v.push_back(x % 10);
//             x /= 10;
//         }
//         int l = 0, r = v.size() - 1;
//         while (l <= r) {
//             if (v[l] != v[r])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;        
//     }
// };

// compare half of the number
class Solution {
public:
    bool isPalindrome(int x) {

    // However, if the reversed number 
    // is larger than int.MAX, we will hit integer overflow problem.

    if (x < 0)
        return false;

    // if 0 ending but not zero
    if (x % 10 == 0 && x != 0)
        return false;

    int revertedNumber = 0;
    // this is when we know we reach half of the x
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }

    // When the length is an odd number, we can get rid of the middle digit
    // by revertedNumber/10 For example when the input is 12321, at the end
    // of the while loop we get x = 12, revertedNumber = 123, since the
    // middle digit doesn't matter in palidrome(it will always equal to
    // itself), we can simply get rid of it.

    return x == revertedNumber || x == revertedNumber / 10;

    }
};

// string version
// class Solution {
// public:
//     bool isPalindrome(int x) {

//         if (x < 0)
//             return false;

//         string s = to_string(x);
//         int l = 0, r = s.size() - 1;
//         while (l <= r) {
//             if (s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
// };
