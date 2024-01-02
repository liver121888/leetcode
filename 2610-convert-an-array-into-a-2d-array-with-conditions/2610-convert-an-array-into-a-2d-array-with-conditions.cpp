class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> counts(nums.size());

        // for (auto num : nums) {
        //     counts[num - 1]++;
        // }
        
        // int rowNum = *max_element(counts.begin(), counts.end());
        
        vector<vector<int>> ans;

        for (int c : nums) {
            // push empty vector!
            if (counts[c - 1] >= ans.size()) {
                ans.push_back({});
            }
            
            // Store the integer in the list corresponding to its current frequency.
            ans[counts[c - 1]].push_back(c);
            counts[c - 1]++;
        }
        return ans;
    }
};