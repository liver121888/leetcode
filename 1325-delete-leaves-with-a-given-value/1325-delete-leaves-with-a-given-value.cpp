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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root)
            return 0;
        
        TreeNode* leftSubTree = removeLeafNodes(root->left, target);
        root->left = leftSubTree;
        TreeNode* rightSubTree = removeLeafNodes(root->right, target);
        root->right = rightSubTree;
        if (!leftSubTree && !rightSubTree)
            if (root->val == target)
                root = nullptr;
                
        return root;        
    }
};