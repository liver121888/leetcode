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

// Follow up: If the BST is modified often 
// (i.e., we can do insert and delete operations) 
// and you need to find the kth smallest frequently, 
// how would you optimize?

// inorder traversal
// find the k element
// 1 indexed
// k-1 index on the tree
// inorder and return the value on the kth nodes

class Solution {
public:

    int ans = 0;
    int k_;
    int cnt = 0;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);
        if (cnt == k_ - 1)
            ans = root->val;
        cnt++;
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        k_ = k;
        inorder(root);
        return ans;
    }
};