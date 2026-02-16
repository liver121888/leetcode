// we can use stack to simulate the backspace
// Follow up: Can you solve it in O(n) time and O(1) space?
// what if we process the string first

// Input: s = "a#c", t = "b"
// we can also view from the back
// if we met with a backsapce, we skip a word
class Solution {
public:

    string process(string input) {

        stack<char> st;

        for (auto c : input) {

            if (c == '#') {
                if (!st.empty()) {
                    st.pop();
                }
                continue;
            }

            st.push(c);
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }

    bool backspaceCompare(string s, string t) {

        string ns = process(s);
        string nt = process(t);

        return ns == nt;
    }
};