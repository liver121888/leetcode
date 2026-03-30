/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// negative node value so we cannot end early
// we can dfs in an inorder fashion and reset state so we don't copy values
// when reach the leaves check for the sum
// time: O(n)
// space: O(h) for recursion

class Solution {
public:

    vector<vector<int>> ans;

    void preorder(vector<int>& state, int currSum, TreeNode* root, int target) {

        if (!root)
            return;

        state.push_back(root->val);
        currSum += root->val;

        // leaf node
        if (!root->left && !root->right) {
            cout << "leaves: " << root->val << endl;
            if (currSum == target)
                ans.push_back(state);
            return;
        }

        if (root->left) {
            preorder(state, currSum, root->left, target);
            state.pop_back();
        }
        if (root->right) {
            preorder(state, currSum, root->right, target);
            state.pop_back();
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if (!root)
            return {};

        vector<int> state;
        preorder(state, 0, root, targetSum);
        return ans;
    }



};