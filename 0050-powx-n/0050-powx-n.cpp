
// should be able to solve this in O(log(n)) time
// one naive way is to go all the way to n which will take O(n) time
// we can design a recursion to have O(n) space and O(log(n)) time

// n might also be -2
// we still have the same calculation
// but in the end we divided by the number we calculated

// 2.1 ^ 10
// 2.1 ^ 5 * 2.1 ^ 5
// 2.1 ^ 2
// 2.1 ^ 1 
// 2.1^0 -> 1

class Solution {
public:

    double helper(double x, int n) {

        // cout << n << endl;
        if (n == 0)
            return 1;
        
        double half = helper(x, n/2);

        // if odd
        if (n & 1) {
            return half*half*x;
        }

        // if (n % 2 != 0)
        // 遠本寫成 if (n % 2 == 1)
        // 這樣遇到負數就出事了
        // 因為 n % 2 = -1

        return half*half;
    }

    double myPow(double x, int n) {

        double result = helper(x, n);

        if (n < 0)
            return 1/result;
        
        return result;
    }
};