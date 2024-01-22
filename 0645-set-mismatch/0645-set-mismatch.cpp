class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long x = 0;
        long long y = 0;

        for (int i = 1; i < n + 1; i++) {
            x += nums[i - 1] - i;
            y += nums[i - 1] * nums[i - 1] - i * i;
        }     
            
            
        int missing = (y - x * x) / (2 * x);
        int duplicate = missing + x;

        return {duplicate, missing};
    }
};