
// should be able to solve this in O(log(n)) time
// one naive way is to go all the way to n which will take O(n) time
// we can design a recursion to have O(logn) space and O(log(n)) time

// n might also be -2
// we still have the same calculation
// but in the end we divided by the number we calculated

// 2.1 ^ 10
// 2.1 ^ 5 * 2.1 ^ 5
// 2.1 ^ 2
// 2.1 ^ 1 
// 2.1^0 -> 1

// class Solution {
// public:

//     double helper(double x, int n) {

//         // cout << n << endl;
//         if (n == 0)
//             return 1;
        
//         double half = helper(x, n/2);

//         // if odd
//         if (n & 1) {
//             return half*half*x;
//         }

//         // if (n % 2 != 0)
//         // 遠本寫成 if (n % 2 == 1)
//         // 這樣遇到負數就出事了
//         // 因為 n % 2 = -1

//         return half*half;
//     }

//     double myPow(double x, int n) {

//         double result = helper(x, n);

//         if (n < 0)
//             return 1/result;
        
//         return result;
//     }
// };





// recursion
// class Solution {
// public:
//     double fastPow(double x, long long n) {
//         if (n == 0) return 1.0;

//         double half = fastPow(x, n / 2);

//         if (n & 1) {
//             return half * half * x;
//         }

//         return half * half;
//     }

//     double myPow(double x, int n) {
//         // 先換成long long再取負
//         // 因為如果n = INT_MIN
//         // 直接取 n = -n
//         // 會溢位
//         long long N = n;

//         if (N < 0) {
//             x = 1 / x;
//             N = -N;
//         }

//         // 讓fastPow專心處理double的正整數次方
//         return fastPow(x, N);
//     }
// };

// iterative
class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }

        // Handle case where, n < 0.
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }

        // Perform Binary Exponentiation.
        // 比起iterative的一個一個乘
        // 用一次跳兩然後把x變平方的方式快速結束
        double result = 1;
        while (n) {
            // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
            if (n % 2 == 1) {
                result = result * x;
                n -= 1;
            }
            // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
            x = x * x;
            n = n / 2;
        }
        return result;
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long)n);
    }
};
