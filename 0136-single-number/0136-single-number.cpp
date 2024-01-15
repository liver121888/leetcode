class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];        
        
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = cur ^ nums[i];
        }
        return cur;
    }
};