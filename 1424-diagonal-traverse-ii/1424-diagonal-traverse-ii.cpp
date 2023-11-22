class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> diagonals;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                diagonals[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        int d = 0;
        while (diagonals.find(d) != diagonals.end()) {
            for (auto num : diagonals[d]) {
                ans.push_back(num);
            }
            d++;
        }
        return ans;
        
        
    }
};