
// backtrack to list out all possibilities
// state vector
// every step we pick a number that we haven't use
// and put it in the vector

// 這份程式的複雜度是：
// 時間： O(n^2 * n!)
// 額外空間： O(n)

// n! comes from all the permutation possibilities
// every permutation for each num we do a linear search
// so (n^2)

class Solution {
public:

    void backtrack(vector<vector<int>>& ans, vector<int>& currState, const vector<int>& nums) {
        
        // base case
        if (currState.size() == nums.size()) {
            ans.push_back(currState);
            return;
        }


        for (const int& num : nums) {
            if (find(currState.begin(), currState.end(), num) == currState.end()) {
                // modify state
                currState.push_back(num);
                // backtrack
                backtrack(ans, currState, nums);
                // reset state
                currState.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> currState;
        backtrack(ans, currState, nums);
        return ans;        
    }
};