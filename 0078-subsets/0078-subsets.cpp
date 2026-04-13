
// all possible subsets (the power set).
// All the numbers of nums are unique.
// we can back track and put in the numbers
// sequence is not important here
// all numbers are unique
// at every position we can either choose to put in 
// or not put in
// time complexity O(n*2^n) beacuase we need 2^n to generate each subset
// and O(n) time to copy from the state to ans
// space: O(n) because of the recursion stack, and the state array 
class Solution {
public:

    void backtrack(vector<vector<int>>& ans, vector<int>& state, 
        const vector<int>& nums, int i) {

        // base case
        if (i == nums.size()) {
            // this is O(n)
            ans.push_back(state);
            return;
        }

        state.push_back(nums[i]);
        backtrack(ans, state, nums, i+1);
        state.pop_back();
        backtrack(ans, state, nums, i+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> state;
        backtrack(ans, state, nums, 0);
        return ans;
        
    }
};