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

    int mySqrt(int x) {

        unsigned long long l = 0, r = x;
        while (l <= r) {
            unsigned long long mid = l + (r-l)/2;       
            if (mid*mid > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;        
    }
};
