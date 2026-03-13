class Solution {
public:

    // 00111110
    // 01111100

    // we can take every bit
    // and build the number in the opposite way

    int reverseBits(int n) {
        
        // 32 bit
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int lsb = n & 1;  // 获取 n 的最低有效位
            ans = (ans << 1) | lsb;  // 左移 ans，并将 lsb 加到 ans 中
            n >>= 1;  // 将 n 右移，处理下一个位
        }
        return ans;
    }
};