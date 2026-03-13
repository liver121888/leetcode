class Solution {
public:

    // 00111110
    // 01111100

    // we can take every bit
    // and build the number in the opposite way
    // 

    int reverseBits(int n) {
        
        // 32 bit
        int ans = 0;
        int cnt = 1;
        while (n) {
            int lsb = n & 1;
            ans |= lsb;
            ans <<= 1;
            cnt++;
            bitset<32> bits(ans);
            std::cout << "bitset: " << bits << " " << cnt << std::endl;
            n >>= 1;
        }
        // n might become 0 before we hit 32 times
        while (cnt < 32) {
            ans <<= 1;
            cnt++;
        }
        bitset<32> bits(ans);
        std::cout << "bitset: " << bits << " " << cnt << std::endl;

        return ans;
    }
};