#include <stack>

class Solution {
public:
    bool isValid(string s) {
        // ASCII: 40 ( 41 ) 91 [ 93 ] 123 { 125 }
        stack<char> st;
        for (auto ch : s) {
            // first we peak the stack
            if (!st.empty()) {
                if (st.top() == ch - 1 || st.top() == ch - 2)
                    st.pop();
                else
                    st.push(ch);  
            }     
            else
                st.push(ch);  
        }
        
        if (st.empty())
            return true;
        else
            return false;
    }
};