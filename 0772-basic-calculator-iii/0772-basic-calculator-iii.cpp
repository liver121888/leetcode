// like Basic Calculator II 
// but with recursion

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

    int helper(string& s, int& i) {
        stack<int> st;
        int currentNumber = 0;
        char operation = '+';

        for (; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            // 遇到 '('，先把括號裡整段算完，結果當成 currentNumber
            if (c == '(') {
                i++; // 進到括號內
                currentNumber = helper(s, i);
            }

            // cout << c << endl;
            // 當前字元是運算子、右括號、或已到字串結尾 -> 該把前一個數字結算進 stack
            if ((!isdigit(c) && c != ' ' && c != '(') || i == s.length() - 1) {
                if (operation == '+') {
                    st.push(currentNumber);
                } else if (operation == '-') {
                    st.push(-currentNumber);
                } else if (operation == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currentNumber);
                } else if (operation == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / currentNumber);
                }

                currentNumber = 0;

                // 遇到 ')' 代表這一層 expression 結束
                if (c == ')') {
                    break;
                }

                operation = c;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};