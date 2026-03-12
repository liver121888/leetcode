
// Follow up: If this function is called many times, 
// how would you optimize it?
class Solution {
public:

    // can we do O(n)
    // The run time depends on the number of 1-bits in n. 
    // In the worst case, all bits in n are 1-bits. 
    // In case of a 32-bit integer, the run time is O(1).
    // int hammingWeight(int n) {
        
    //     int count = 0;
    //     while (n) {
    //         n &= (n - 1);  // Clear the lowest set bit
    //         count++;
    //     }
    //     return count;
    // }



    // O(logn)
    int hammingWeight(int n) {

        int ans = 0;
        while (n) {
            ans += n & 1;
            n >>= 1;
        }

        // hamming distance 
        // int diff = n ^ 0;

        return ans;
    }
};