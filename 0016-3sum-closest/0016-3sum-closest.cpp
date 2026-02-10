// min(abs(nums[i] + nums[j] + nums[k] - target))
// nums[j] + nums[k] should be close to -(nums[i] - target)
// if to big, move to left
// if to small move to right
// brute force, find all possibilities then compare
// O(n^3)

// fix one number
// binary the rest
class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        
        int currMinDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && currMinDiff != 0; i++) {
            int l = i + 1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(currMinDiff)) {
                    currMinDiff = target - sum;
                }
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                } 

            }

        }
        return target-currMinDiff;
    }
};