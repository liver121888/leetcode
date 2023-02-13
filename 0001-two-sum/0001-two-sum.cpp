class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        int tmp, rest;
        vector<int> ans;
        for (int i = 0; i < length; i++) {
            tmp = nums.at(i);
            rest = target - tmp;
            for (int j = i + 1; j < length; j++) {
                if (nums.at(j) == rest) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};