class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // cannot use same element twice

        unordered_map<int, int> num2idx;

        for (int i = 0; i < nums.size(); i++) {
            num2idx[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if (num2idx.find(rest) != num2idx.end() && num2idx[rest] != i)
                return {i, num2idx[rest]};
        }

        return {};
        
    }
};