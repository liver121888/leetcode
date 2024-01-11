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
class Solution {
public:
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        // brute force: check each pair->v**2
        dfs(root);
        return ans;
    }

    pair<int, int> dfs(TreeNode* root) {
        if (!root)
            return pair<int, int>(INT_MAX, INT_MIN);
        if (!root->left && !root->right)
            return pair<int, int>(root->val, root->val);
        
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        int minVal = min(left.first, right.first);
        int maxVal = max(left.second, right.second);
        
        ans = max(ans, max(abs(minVal - root->val), abs(maxVal - root->val)));
        
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        return pair<int, int>(minVal, maxVal);
    }
    
};