// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5

// s consists of integers and operators ('+', '-', '*', '/') 
// separated by some number of spaces.

// /0 does not exist
// non-negative int

// " 3+5 / 2 "
// 3+2*2
// stack
// [3, +, 2]
// * 2
// 2*2

// 5/2 -> comes first
// ignore spaces in between

// " 3+5 / 2 "
// 3 +
// top is not operator
// we push
// * or / operator
// 3+5/
// 5/2
// 3+2
// + and - signs opearator and evaluate the expression -> 5

// 1
// stack is empty

// "3+4" -> 7

// 3+2*2/4
// 3+4/4
// 4

// O(N)
// O(N)

class Solution {
public:

    // if isdigit
    // accumulating a number eg 35 -> 3 * 10 + 5
    // else
    // close the current number accumulation if it exist
    // check the top of the stack if it's * or /
    // we operate and push back the result
    // we also 
    
    // push in the current char
    // chekc if it's a space -> skip

    // see the priority of the operator
    // if stack is not empty
    // we evaluate and return the ans

    // stack<int> stack;
    // stack<string> st;

    int calculate(string s) {
        int len = s.length();
        if (len == 0) 
            return 0;

        stack<int> st;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (isdigit(c))
                currentNumber = currentNumber * 10 + (c - '0');

            if (!isdigit(c) && !iswspace(c) || i == len - 1) {
                
                if (operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currentNumber);
                } else if (operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currentNumber);
                } else if (operation == '-') {
                    st.push(-currentNumber);
                } else {
                    st.push(currentNumber);
                }
                operation = c;
                currentNumber = 0;
            }

        }
        
        int ans = 0;
        while (st.size() != 0) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};