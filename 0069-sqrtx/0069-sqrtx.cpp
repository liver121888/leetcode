class Solution {
public:

    // x is from 0 to INT_MAX
    // edge case: 0 still 0

    // we can do like a binary search
    // l = 0, r = x
    // binary and square and compare with x
    // time O(log(n))
    // space O(1)

    // 4 -> l = 0, r = 4
    // mid = 2
    // 2*2 = 4 return 2

    // 8, l = 0, r = 8
    // mid = 4, 4^2 = 16
    // r = 4, l = 0
    // 2^2 < 8
    // l = 3 r = 4
    // 9 > 8
    // l = 3, r = 3
    // r--;
    // return r
    // we are finding the last value < target

    // signed integer overflow: 1073697799 * 1073697799 
    // cannot be represented in type 'int'

    // int mySqrt(int x) {

    //     unsigned long long l = 0, r = x;
    //     while (l <= r) {
    //         unsigned long long mid = l + (r-l)/2;
    //         // 容易overflow
    //         // if (mid*mid > x)
    //         // 安全，但會有divide by 0 問題
    //         if (mid > x/mid) {
    //             r = mid - 1;
    //         } else {
    //             l = mid + 1;
    //         }
    //     }
    //     return r;        
    // }

    // 更好寫法, 不用型別提昇
    int mySqrt(int x) {
        if (x < 2) 
            return x;
        // 不用搜到x, 只要收到x/2就夠
        // 特判0所以後面可以安全的去做除法
        int l = 1, r = x / 2;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (mid <= x / mid) {
                // 這個想法也不錯
                // 在可能是答案的範圍內就先記住答案
                ans = mid;      // mid^2 <= x，先記住
                l = mid + 1;    // 試更大
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }


};



