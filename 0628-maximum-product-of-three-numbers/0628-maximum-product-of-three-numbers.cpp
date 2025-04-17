class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // sequence doesn't matter
        // three numbers how to come up with the biggest?
        // all positive
        // 2 negative 1 positive

        // sort the array then compare the largest 3 and least 3

        sort(nums.begin(), nums.end());

        // nums.size() - 1

        return max(nums[0] * nums[1] * nums[nums.size()-1],
            nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3]);
        

    }
};