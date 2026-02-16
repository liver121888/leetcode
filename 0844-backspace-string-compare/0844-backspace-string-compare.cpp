// we can use stack to simulate the backspace
// Follow up: Can you solve it in O(n) time and O(1) space?
// what if we process the string first

// Input: s = "a#c", t = "b"
// we can also view from the back
// if we met with a backsapce, we skip a word
class Solution {
public:

    // string process(string input) {

    //     stack<char> st;

    //     for (auto c : input) {

    //         if (c == '#') {
    //             if (!st.empty()) {
    //                 st.pop();
    //             }
    //             continue;
    //         }

    //         st.push(c);
    //     }

    //     string res = "";
    //     while (!st.empty()) {
    //         res += st.top();
    //         st.pop();
    //     }

    //     return res;
    // }

    int nextValidIndex(const string& s, int i) {
        int skip = 0;
        while (i >= 0) {
            if (s[i] == '#') {
                skip++;
                i--;
            } else if (skip > 0) {
                skip--;
                i--;
            } else {
                break; // s[i] is a valid character to compare
            }
        }
        return i;
    }


    bool backspaceCompare(string s, string t) {

        // string ns = process(s);
        // string nt = process(t);

        // return ns == nt;

        // two pointers

        // "a#c", t = "b"

        // s = 2
        // t = 0

        // "ab#c", t = "ad#c"
        // sPtr = 3
        // tPtr = 3
        // 2, 2
        // sPtr = 1, sBCnt = 1
        // tPtr = 1, tBCnt = 1

        // 0, 0

        int i = (int)s.size() - 1;
        int j = (int)t.size() - 1;

        while (i >= 0 || j >= 0) {
            i = nextValidIndex(s, i);
            j = nextValidIndex(t, j);

            // both finished
            if (i < 0 && j < 0) return true;
            // one finished, the other not
            if (i < 0 || j < 0) return false;

            if (s[i] != t[j]) return false;

            i--;
            j--;
        }
        return true;



    }
};