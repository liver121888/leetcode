class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 一樣的設成0
        // 不一樣的設成1
        // a ^ 0 = a
        // a ^ a = 0
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr ^= nums[i];
        }
        return curr;
    }
};