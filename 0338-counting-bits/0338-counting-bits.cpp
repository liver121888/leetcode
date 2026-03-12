// O(n log n)
// get a number
// >> then check if it's one

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int num = i;
            int cnt = 0;
            while (num) {
                cnt += num & 1;
                num >>= 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};