/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // pass left or right
    // If the root matches p, the recursion stops, 
    // and we don't check further in that subtree. 
    // Similarly, if q doesn't exist in the subtree of p, 
    // we won't know that q is missing, leading to incorrect results.

    // so after it return a LCA, we need to check the subtree
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)
            return nullptr;
            
        if (root == p || root == q)
            return root;

        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }

    // under p serach q
    bool dfs(TreeNode* node, TreeNode* target) {

        // Base case: target found
        if (node == target) 
            return true;

        // Base case: reached null, target not found
        if (!node) 
            return false;

        // Recursive case: search target in left or right subtree
        return dfs(node->left, target) || dfs(node->right, target);

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Step 1: find LCA
        TreeNode* ans = LCA(root, p, q);

        // cout << ans->val << endl;

        // Step 2: Check if the LCA is p, meaning q must be in p's subtree
        if (ans == p) {
            // Verify if q is in the subtree of p
            return dfs(p, q) ? p : nullptr;
        } else if (ans == q) {
            // Step 3: Check if the LCA is q, meaning p must be in q's subtree
            // Verify if p is in the subtree of q
            return dfs(q, p) ? q : nullptr;
        }

        // Step 4: If neither p nor q is the ancestor of the other, return the
        // LCA
        return ans;
        
    }
};