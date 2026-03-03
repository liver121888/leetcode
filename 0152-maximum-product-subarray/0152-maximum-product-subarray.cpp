// 為什麼這樣就夠？
// 因為「奇數個負數」導致整段乘積為負時，最大解一定是把其中一邊含負數的 prefix 或 suffix 去掉。
// 左掃會考慮所有 prefix product；右掃會考慮所有 suffix product，所以兩邊都掃到就 cover 了。
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         long long ans = nums[0];

//         long long prod = 1;
//         for (int x : nums) {
//             prod *= x;
//             ans = max(ans, prod);
//             if (x == 0) prod = 1; // reset at zero
//         }

//         prod = 1;
//         for (int i = (int)nums.size() - 1; i >= 0; --i) {
//             prod *= nums[i];
//             ans = max(ans, prod);
//             if (nums[i] == 0) prod = 1;
//         }

//         return (int)ans;
//     }
// };

// DP 同時維護 curMax/curMin（因為負負得正）
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            // 在這個點有三個option
            // 比較哪個option是最大和最小的
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            // Update max_so_far after updates to min_so_far to avoid
            // overwriting it
            max_so_far = temp_max;
            // Update the result with the maximum product found so far
            result = max(max_so_far, result);
        }

        return result;
    }
};