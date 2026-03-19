
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).

// There will be no two consecutive operators in the input.

class Solution {
public:

    // not * /
    // we need to calculate the parenthesis in pair
    // "(1+(4+5+2)-3)+(6+8)"
    // when we see the )
    // we need to evaluate all the way back to the prev (
    // might be negative number
    // might be ' '

    // There will be no two consecutive operators in the input.
    // stack<string>
    // [(,1,+,(,4, +, 5, +, 2], )

    // "- 1" and "-(2 + 3)"
    // (-2 + 3)
    // (? - 2 -> X
    
    // pop all the way back to (
    // and then evaluate and push in
    // (, 1, +, 11, -, 3)
    // 9 + 14 -> 23

    // + -1
    // when can we dicern a negative number
    // number -> push(-number)

    // " 2-1 + 2 "

    // use - operator as the magnitude for the operand to the right of the operator.
    // for e.g. A−B−C could be re-written as A+(−B)+(−C).


    // 遇到字符             動作                            意義
    // 數字 (0-9)        num = num * 10 + char      處理像 "123" 這種多位數。
    // 符號 (+/-)        res += sign * num           結算左邊的數字，並更新下一段的 sign。
    // 左括號 (()   stack.push(res, sign)           暫存外面的進度，進去括號內「白手起家」。
    // 右括號 ())   res = (res + sign * num) *    算完括號內的總值，乘上括號前的正負號，再加上括號前的基礎值。
    //           stack.pop() + stack.pop() 
    // 把正負號化成了一個int!

    int calculate(string s) {

        stack<int> st;
        long long operand = 0;
        // why we need result? because we might have (A - (B - C))
        // we need to apply the negative sign to the whole result on (B-C)
        int result = 0; // For the on-going result
        int sign = 1;  // 1 means positive, -1 means negative
        int n = s.length();

        for (int i = 0; i < n; i++) {

            char c = s[i];
            // cout << c << endl;
            if (isdigit(c)) {
                operand = 10 * operand + (c - '0');
            } else if (c == '+') {

                // Evaluate the expression to the left,
                // with result, sign, operand
                result += sign * operand;

                // Save the recently encountered '+' sign
                sign = 1;

                // Reset operand
                operand = 0;
            } else if (c == '-') {

                result += sign * operand;
                sign = -1;
                operand = 0;
            }  else if (c == '(') {

                // Push the result and sign on to the stack, for later
                // We push the result first, then sign
                st.push(result);
                st.push(sign);

                // Reset operand and result, as if new evaluation begins for the new sub-expression
                sign = 1;
                result = 0;
            } else if (c == ')') {

                // Evaluate the expression to the left
                // with result, sign and operand
                result += sign * operand;

                // ')' marks end of expression within a set of parenthesis
                // Its result is multiplied with sign on top of stack
                // as stack.pop() is the sign before the parenthesis
                result *= st.top();
                st.pop();

                // Then add to the next operand on the top.
                // as stack.pop() is the result calculated before this parenthesis
                // (operand on stack) + (sign on stack * (result from parenthesis))
                result += st.top();
                st.pop();

                // Reset the operand
                operand = 0;
            }

        }

        return result + (sign * operand);

    }
};