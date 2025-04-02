// time: O((n * n - 1 * ... 1  = n!) * n)

class Solution {

    int n = -1;
public:

    void dfs(const vector<int>& nums, vector<int>& state, vector<vector<int>>& ans) {
        
        if (state.size() == n) {
            // cout << "ans insert state: [";
            // for (auto num : state)
            //     cout << num << " ";
            // cout << "]" << endl;
            ans.push_back(state);
            return;
        }

        // cout << "dict: [";
        // for (auto num : dict)
        //     cout << num << " ";
        // cout << "]" << endl;

        // cout << "state: [";
        // for (auto num : state)
        //     cout << num << " ";
        // cout << "]" << endl;

        for (int num : nums) {
            if (find(state.begin(), state.end(), num) == state.end()) {
                state.push_back(num);
                dfs(nums, state, ans);
                // reset state
                state.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();
        vector<vector<int>> ans;
        vector<int> curr = {};
        dfs(nums, curr, ans);
        return ans;
    }
};