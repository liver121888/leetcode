
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 唯一會 overflow 的 case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // 判斷答案是否為負
        // XOR
        bool negative = (dividend < 0) ^ (divisor < 0);

        // 全部轉成負數，避免 abs(INT_MIN) overflow
        // 因為負數有比較大的range
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int ans = 0; // 用負數累加 quotient

        while (dividend <= divisor) {
            int cur = divisor;
            int cnt = -1;

            // cur + cur 不能小於 INT_MIN，否則 overflow
            // dividend <= cur + cur 代表還扣得動更大的倍數
            while (cur >= INT_MIN - cur && dividend <= cur + cur) {
                cur += cur;
                cnt += cnt;
            }

            dividend -= cur;
            ans += cnt;
        }

        return negative ? ans : -ans;
    }
};




// class Solution {
// public:

    // truncate toward zero
    // check of 0, divisor != 0 is known
    // check sign of the numbers to know the sign of the result
    // then, apply integer division, take that number and see
    // if we should make the sign

    // 0/x
    // INT_MIN/INT_MAX
    // INT_
    // 10 3
    // 7 4 1

//     int divide(int dividend, int divisor) {
        
//         bool isNegative = true;
//         if ((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0)) {
//             isNegative = false;
//         }

//         // transform to canical space
//         dividend = dividend == INT_MIN ? INT_MAX : abs(dividend);
//         divisor = divisor == INT_MIN ? INT_MAX : abs(divisor);
        
//         if (dividend < divisor)
//             return 0;

//         // divide two integers without using multiplication, division, and mod operator.
//         // keep deducting
//         int ans = 0;
//         while (dividend >= divisor) { 
//             dividend -= divisor;
//             ans += 1;
//         }

//         if (isNegative) {
//             ans = (-1) * ans;
//         }

//         return ans;
        
//     }
// };