class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // vector<vector<int>> ans(nums.size()/3, vector<int>(3, 0));
        // ans[0][0] = nums[0];
        // ans[0][1] = nums[1];
        
        
        // for (int i = 2; i < nums.size(); i++) {    
        //     cout << nums[i] << endl;
        //     if (i % 3 == 2 && nums[i] - nums[i - 2]  > k)
        //         return {};
        //     ans[i/3][i % 3] = nums[i];
        // }
        
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};