
// this is a dynamic programming problem
// for each index i
// dp[i] = max(j[i]) for j < i && j[i] > nums[i]
// jump to the back of the array will not increase the value
// but! you can jump to the back to lower the value
// then jump to the front of the array to have the maximum value

// Input: nums = [2,1,3]
// Output: [2,2,3]

// Input: nums = [2,3,1]
// Output: [3,3,3]

// brute force
// for each i
// look before to find the max value
// look back to find the max value
// if maxBefore > maxAfter && maxBefore > nums[i]
// maxBefore
// if maxBefore < maxAfter && nums[i] > minA

// 2 2 3
// 1 1 3

// 2

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        vector<int> ans(n);

        int start = 0;
        int segmentMax = nums[0];

        for (int i = 0; i < n; i++) {
            segmentMax = max(segmentMax, nums[i]);

            // 到尾巴，或這裡可以切段
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = segmentMax;
                }

                start = i + 1;
                if (start < n) {
                    segmentMax = nums[start];
                }
            }
        }

        return ans;
    }
};