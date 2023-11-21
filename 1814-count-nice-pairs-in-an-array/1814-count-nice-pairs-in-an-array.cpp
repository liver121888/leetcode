class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if (n == 1)
            return ans;
        vector<int> diff(n);
        int num = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            num = nums[i];
            int result = 0;
            while (num > 0) {
                result = result * 10 + num % 10;
                num /= 10;
            }
            diff[i] = nums[i] - result;
        }
        
        // for (auto i : revnums) {
        //     cout << i << endl;
        // }
                
        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            ans = (ans + counts[diff[i]]) % int(1e9 + 7);
            counts[diff[i]] += 1;
        }
        
        return ans;
    }
};