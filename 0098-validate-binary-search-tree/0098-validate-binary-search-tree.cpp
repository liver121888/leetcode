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

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 
// save result inorder traversal
// check if it's strictly increasing
// O(n)
// O(n)
class Solution {
public:

    // vector<int> result;

    // void inorder(TreeNode* root) {

    //     if (!root)
    //         return;

    //     inorder(root->left);
    //     result.push_back(root->val);
    //     inorder(root->right);
    // }

    // bool isValidBST(TreeNode* root) {

    //     inorder(root);
    //     for (int i = 1; i < result.size(); i++) {

    //         if (result[i] <= result[i-1])
    //             return false;
    //     }

    //     return true;
        
    // }


    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) { return inorder(root); }

    bool inorder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }

};