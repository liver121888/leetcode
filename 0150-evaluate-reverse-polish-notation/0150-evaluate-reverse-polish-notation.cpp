// we use stack to record the operator and operand
// when we met an operand, we pop two and calculate the result and push it back

class Solution {
public:
    int evalRPN(vector<string>& tokens) {


        stack<string> st;

        for (const auto& token : tokens) {

            // token is an operator
            // we pop and calculate

            // token is an operand
            // we push

            if (!(token == "+" || token == "-" 
                || token == "*" || token == "/")) {
                
                st.push(token);

            } else {
                string op1Str = st.top();
                st.pop();
                string op2Str = st.top();
                st.pop();

                int op1 = stoi(op1Str);
                int op2 = stoi(op2Str);

                // cout << op1 << " " << op2 << endl;

                if (token == "+") {
                    st.push(to_string(op2+op1));
                } else if (token == "-") {
                    st.push(to_string(op2-op1));
                } else if (token == "*") {
                    st.push(to_string(op2*op1));
                } else {
                    st.push(to_string(op2/op1));
                }
            }

        }

        return stoi(st.top());
    }
};