class Solution {
public:
    int calculate(string s) {

        int len = s.length();
        if (len == 0) return 0;
        stack<int> st;
        int currentNumber = 0;
        char operation = '+';

        string tmp;
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    st.push(-currentNumber);
                } else if (operation == '+') {
                    st.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;

    }
};