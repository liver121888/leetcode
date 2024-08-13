class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> initState;
        dfs(result, initState, candidates, target, 0);
        return result;        
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &currentCombination, vector<int> &candidates, int target, int start) {
        // Base case: if the target is 0, add the current combination to the result
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }

        // Iterate through the candidates starting from 'start' index
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the current candidate exceeds the target, stop further exploration
            if (candidates[i] > target) break;

            // Include the current candidate in the combination
            currentCombination.push_back(candidates[i]);

            // Recurse with reduced target and next index
            dfs(result, currentCombination, candidates, target - candidates[i], i + 1);

            // Backtrack by removing the last element added
            currentCombination.pop_back();
        }
    }
};