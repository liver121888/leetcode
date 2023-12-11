class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l;
        int r;
        int val;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                val = nums[l] + nums[r] + nums[i];
                if (val > 0) 
                    r--;
                else if (val == 0) {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
                else
                    l++;
            }
        }
        return result;
    }
};