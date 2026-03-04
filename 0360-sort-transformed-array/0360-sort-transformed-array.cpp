class Solution {
public:
    int f(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n - 1;
        int idx = (a >= 0) ? n - 1 : 0;

        while (l <= r) {
            int left = f(nums[l], a, b, c);
            int right = f(nums[r], a, b, c);

            if (a >= 0) {
                if (left > right) {
                    ans[idx--] = left;
                    l++;
                } else {
                    ans[idx--] = right;
                    r--;
                }
            } else {
                if (left < right) {
                    ans[idx++] = left;
                    l++;
                } else {
                    ans[idx++] = right;
                    r--;
                }
            }
        }

        return ans;
    }
};