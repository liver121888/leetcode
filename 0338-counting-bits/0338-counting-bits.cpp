




class Solution {
public:

    // built in 
    // time O(n)
    // space O(n)
    // vector<int> countBits(int n) {
    //     vector<int> ans(n+1);
    //     for (int i = 0; i <= n; i++) {
    //        ans[i] = __builtin_popcount(i);
    //     }
    //     return ans;
    // }



    // O(n) solution
    // Use previous count results to generate 
    // the count for a new integer.
    // P(x+b) = P(x) + 1, b=2^m >x
    // vector<int> countBits(int n) {
    //     vector<int> ans(n+1);
    //     int x = 0;
    //     int b = 1;
    //     while (b <= n) {
    //         while (x < b && x + b <= n) {
    //             ans[x + b] = ans[x] + 1;
    //             ++x;
    //         }        
    //         x = 0; // reset x
    //         b <<= 1; // b = 2b
    //     }
    //     return ans;
    // }

    // lsb dp
    // P(x) = P(x/2)+(x mod 2)
    // vector<int> countBits(int n) {
    //     vector<int> ans(n + 1);
    //     for (int x = 1; x <= n; ++x) {
    //         // x / 2 is x >> 1 and x % 2 is x & 1
    //         ans[x] = ans[x >> 1] + (x & 1); 
    //     }
    //     return ans;
    // }

    // dp with rightmost set bit
    // P(x)=P(x&(x−1))+1
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int x = 1; x <= n; ++x) {
            ans[x] = ans[x & (x - 1)] + 1;
        }
        return ans;
    }



    // O(n log n) solution
    // 因為13 需要 4 位二进制来表示，log_2(i) 给出了这个位数的估算。
    // 总结：数字 i 的二进制表示长度为 O(log i)
    // get a number
    // vector<int> countBits(int n) {
    //     vector<int> ans;
    //     for (int i = 0; i <= n; i++) {
    //         int num = i;
    //         int cnt = 0;
    //         while (num) {
    //             cnt += num & 1;
    //             num >>= 1;
    //         }
    //         ans.push_back(cnt);
    //     }
    //     return ans;
    // }

};