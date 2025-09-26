class Solution {
public:

    int ub(const vector<int>& nums, int l, int r, int x) {
        while (l <= r && r < nums.size()) {
            int mid = (l + r) / 2;
            if (nums[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }
        return l;
    }

    int triangleNumber(vector<int>& nums) {

        // how to make triangle?
        // a + b > c
        // a + c > b
        // b + c > a

        if (nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                k = ub(nums, k, nums.size() - 1, nums[i] + nums[j]);
                ans += k - j - 1;
            }
        }

        return ans;
    }
};