// match problem
// we can use a stack to do this
// if stack empty push
// if we encounter ]
// pop entil [
// then take the top so we know the number
// repeat, pop out the number
// push back


class Solution {
public:
    string decodeString(string s) {

        stack<char> st;
        for (const auto& c : s) {

            if (c == ']') {
               string decodedString = "";

                while (st.top() != '[') {
                    decodedString += st.top();
                    st.pop();
                }
                st.pop();

                // get the number k
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k += (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }

                reverse(decodedString.begin(), decodedString.end());

                // push decodedString k times into stack
                while (k-- > 0) {
                    for (char c : decodedString) {
                        st.push(c);
                    }
                }

            } else {

                st.push(c);
            }
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};