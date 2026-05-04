
// can there be repeat charachter
// yes
// is there finite set for the char exist in the string?
// yes, only lower case
// is the size of the string in int?
// yes
// will there be empty string?
// yes

// brute force
// l,r substring
// compare
// l r should always maintain size n
// try different start position
// O(n * n), n here is to traverse to check
// O(1) space, we only traverse

// concate, some extra space but easy to understand
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() &&
               (s + s).find(goal) != string::npos;
    }
};


// prune: we only start checking if the start character is the same
// class Solution {
// public:

//     bool checkString(const string& s, const string& g, int i) {

//         int n = s.size();
//         // int windowLen = 0;
//         // int j = 0;
//         // while (windowLen < n) {

//         //     if (i >= n)
//         //         i = 0;

//         //     if (s[i] != g[j])
//         //         return false;
//         //     j++;
//         //     i++;
//         //     windowLen++;
//         // }
//         // return true;

//         for (int k = 0; k < n; k++) {
//             if (s[(i + k) % n] != g[k])
//                 return false;
//         }
//         return true;
//     }


//     bool rotateString(string s, string goal) {

//         if (s.length() != goal.length())
//             return false;

//         // check empty string
//         if (s.empty() && goal.empty())
//             return true;

//         int n = s.length();
//         // bool valid = false;
//         for (int i = 0; i < n; i++) {
//             // if (s[i] == goal[0])
//             //     valid |= checkString(s, goal, i);
//             if (s[i] == goal[0])
//                 if (checkString(s, goal, i))
//                     return true;
//         }
//         return false;
//     }
// };
