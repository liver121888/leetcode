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


// Height-Balanced
// A height-balanced binary tree is a binary tree in which the depth of the two 
// subtrees of every node never differs by more than one.

// we can solve this using preorder and compare the left dpeth and the right depth

class Solution {
public:

    bool ans = true;

    int getDepth(TreeNode* root, int depth) {

        if (!root)
            return -1;

        int leftDepth = getDepth(root->left, depth+1);
        leftDepth = leftDepth == -1 ? depth : leftDepth;
        int rightDepth = getDepth(root->right, depth+1);
        rightDepth = rightDepth == -1 ? depth : rightDepth;

        if (abs(leftDepth - rightDepth) > 1)
            ans = false;
        return max(leftDepth, rightDepth);
    }


    bool isBalanced(TreeNode* root) {
        int depth = getDepth(root, 0);
        return ans;

    }
};