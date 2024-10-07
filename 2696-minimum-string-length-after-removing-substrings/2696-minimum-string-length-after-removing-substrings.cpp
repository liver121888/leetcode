class Solution {
public:
    int minLength(string s) {
        
        stack<char> st;
        
        for (auto c : s) {
            
            if (st.empty()) {
                st.push(c);
                continue;
            }
            
            char tc = st.top();

            if (tc == 'A' && c == 'B') {
                st.pop();
            } else if (tc == 'C' && c == 'D') {
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        return st.size();
        
    }
};