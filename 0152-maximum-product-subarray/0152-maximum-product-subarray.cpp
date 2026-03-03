class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = nums[0];

        long long prod = 1;
        for (int x : nums) {
            prod *= x;
            ans = max(ans, prod);
            if (x == 0) prod = 1; // reset at zero
        }

        prod = 1;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            prod *= nums[i];
            ans = max(ans, prod);
            if (nums[i] == 0) prod = 1;
        }

        return (int)ans;
    }
};