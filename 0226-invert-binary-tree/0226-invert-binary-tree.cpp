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

// preorder
// if we find out both left right are not empty
// swap
// otherwise we move left to right right to left
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if (!root)
            return nullptr;

        TreeNode* leftSubtree = nullptr;
        TreeNode* rightSubtree = nullptr;
        if (root->left)
            leftSubtree = invertTree(root->left);

        if (root->right)
            rightSubtree = invertTree(root->right);
        
        root->right = leftSubtree;
        root->left = rightSubtree;

        return root;
    }
};