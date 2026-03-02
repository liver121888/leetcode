// class Solution {
// public:
//     bool isPalindrome(string s) {

//         // two pointers
//         // we skip any speical character
//         // compare to lowercase
        
//         // "A man, a plan, a canal: Panama"

//         int l = 0, r = s.length() - 1;

//         while (l < r) {

//             if (!isalnum(s[l])) {
//                 l++;
//                 continue;
//             }

//             if (!isalnum(s[r])) {
//                 r--;
//                 continue;
//             }

//             if (tolower(s[l]) != tolower(s[r]))
//                 return false;
//             else {
//                 l++;
//                 r--;
//             }

//         }
//         return true;
//     }
// };

// concise solution
class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;
        }

        return true;
    }
};