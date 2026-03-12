
// Follow up: If this function is called many times, 
// how would you optimize it?
class Solution {
public:
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