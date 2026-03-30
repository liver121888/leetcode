
class Solution {
public:

    // INT_MIN = -2147483648
    // INT_MAX = 2147483647

    // 如果剛好等於 INT_MAX / 10，那最後一位不能超過 7。

    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            // % 會直接保留sign
            int digit = x % 10;
            x /= 10;

            // 不合法的情況
            // 乘10之後會overflow或是乘十之後一樣但加了新的數overflow
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
                return 0;

            ans = ans * 10 + digit;
        }

        return ans;
    }
};



// class Solution {
// public:
//     int reverse(int x) {

//         // -2^31 <= x <= 2^31 - 1
//         // no long long

//         // If reversing x causes the value to go 
//         // outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

//         int sign = x < 0 ? -1 : 1;
//         // 此處abs可能直接爆
//         // -2^31 -> 2^31先overflow再被assign
//         unsigned int absX = abs(x);

//         unsigned int curr = 0;
//         while (absX) {
//             int digit = absX % 10;
            
//             curr = curr * 10 + digit;
//             // 先乘了在檢查一點用也沒有
//             if (curr > INT_MAX)
//                 return 0;
//             absX /= 10;
//         }

//         return (int)sign * curr;        
//     }
// };

