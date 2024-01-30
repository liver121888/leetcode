class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens) {
            if (s == "+" || s == "-") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(s == "+" ? first + second : first - second);
            } else if (s == "*" || s == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                st.push(s == "*" ? first * second : first / second);
                
            } else
                st.push(stoi(s));
            
        }
        return st.top();
    }
};