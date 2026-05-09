
// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

// we can traverse the string
// when we encounter the space
// we end the current string
// vector of string to store
// we reverse the vector
// or just use a stack to have LIFO
// then output the string
// time: O(n)
// space: O(n)
// edge case: s = ""
// edge case: s = "           "


class Solution {
public:
    string reverseWords(string s) {

        stack<string> st;
        string currString = "";
        bool isCollectingChar = false;
        for (auto c : s) {
            if (!iswspace(c)) {
                currString += c;
                if (!isCollectingChar) {
                    isCollectingChar = true;
                }
            } else {
                if (!currString.empty()) {
                    st.push(currString);
                    currString = "";
                }
                isCollectingChar = false;
            }
        }
        // we need to clear the last string 
        if (!currString.empty())
            st.push(currString);
        string ans = "";
        int n = st.size();
        if (n == 0)
            return ans;
        for (int i = 0; i < n-1; ++i) {
            ans += st.top() + " ";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        return ans;
    }
};