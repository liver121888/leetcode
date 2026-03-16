class Solution {
public:

    // isDigit()
    // not digit
    // if not start reading
    // is space -> continue;
    // is sign -> get the sign
    // if isReading
    // break;

    // if is Digit
    // we start reading
    // keep increasing

    // "   +   " <- possible
    // possible, return 0
    int myAtoi(string s) {

        long long result = 0;
        int sign = 1;
        bool isReading = false;
        for (const auto& c : s) {

            if (!isdigit(c)) {
                if (isReading) {
                    break;
                } else {
                    if (c == ' ')
                        continue;
                    else if (c == '+' || c == '-') {
                        sign = c == '+' ? 1 : -1;
                        isReading = true;
                    }
                    else
                        return 0;
                }
            } else {
                if (!isReading)
                    isReading = true;
                // starts with 0 we need to skip
                // this natrually skips first zeros
                result = result * 10 + (c - '0') * sign;
                // clamp
                result = result > INT_MAX ? INT_MAX : result;
                result = result < INT_MIN ? INT_MIN : result;

            }
        }

        return result;

    }




};