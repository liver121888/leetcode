class Solution {
public:

    int slidingWindowAtMost(vector<int>& nums, int k) {

        int result = 0;
        int currSum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (currSum > k && l <= r) {
                currSum -= nums[l];
                l++;
            }
            result += r - l + 1;
        }
        return result;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindowAtMost(nums, goal) - slidingWindowAtMost(nums, goal - 1);
    }
};