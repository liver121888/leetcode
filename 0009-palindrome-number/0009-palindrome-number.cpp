
// Follow up: Could you solve it without converting the integer to a string?
// isPalindrome
// convert to string and traverse
// O(n), where n is the digits that x has
// we can keep divided by 10
// save a vector


// -121
// 121
// 121/10 -> 12
// 121/100 -> 1

// class Solution {
// public:
//     bool isPalindrome(int x) {

//         if (x < 0)
//             return false;

        
        
//     }
// };


class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
