/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// how can we find the LCA
// All Node.val are unique.
// when we find a node, itself and the child has the node
// or the left and right has both node
// then this is LCA

// Time  : O(N)
// Space : O(H)
// H: height of the tree
// postorder traversal

// 如果是 BST 會變成 Lowest Common Ancestor of a Binary Search Tree
// 如果 tree 很大但只有 parent pointer 那題就是 Lowest Common Ancestor of a Binary Tree III

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;

    }
};

