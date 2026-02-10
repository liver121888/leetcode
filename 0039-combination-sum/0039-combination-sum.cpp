// we need to return the list of possible combination 
// that sums up to target
// we can do dp 
// let target is k and candidates.size = n
// in each position, we branch out n possibilities
// the depth in wores case is k
// time: O(n^k)

// if we dp
// O(k)
// space: O(k)

// we also need to return the possible combination
// we use backtracking and remember to restore state

class Solution {
public:

    void dfs(const vector<int>& candidates, vector<vector<int>>& ans, vector<int> currState, int start, int target) {

        if (target == 0) {
            // sort(currState.begin(),currState.end());
            // if (find(ans.begin(), ans.end(), currState) == ans.end())
            ans.push_back(currState);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int candidate = candidates[i];
            // modify state
            currState.push_back(candidate);
            // put i means that we can reuse elements
            dfs(candidates, ans, currState, i, target-candidate);
            // restore state
            currState.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        dfs(candidates, ans, {}, 0, target);
        return ans;
    }
};