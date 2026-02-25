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

// 核心思想
// 不要：
// 先算高度，再檢查平衡
// 改成：
// 在算高度的同時，就檢查是否平衡
// bottom-up
class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        if (left == -1) return -1;

        int right = dfs(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1)
            return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};


// top-down
// class Solution {
// private:
//     // Recursively obtain the height of a tree. An empty tree has -1 height
//     int height(TreeNode* root) {
//         // An empty tree has height -1
//         if (root == NULL) {
//             return -1;
//         }
//         return 1 + max(height(root->left), height(root->right));
//     }

// public:
//     bool isBalanced(TreeNode* root) {
//         // An empty tree satisfies the definition of a balanced tree
//         if (root == NULL) {
//             return true;
//         }

//         // Check if subtrees have height within 1. If they do, check if the
//         // subtrees are balanced
//         return abs(height(root->left) - height(root->right)) < 2 &&
//                isBalanced(root->left) && isBalanced(root->right);
//     }
// };


// bottom-up 我自己的寫法
// class Solution {
// public:

//     bool ans = true;

//     int getDepth(TreeNode* root, int depth) {

//         if (!root)
//             return -1;

//         int leftDepth = getDepth(root->left, depth+1);
//         leftDepth = leftDepth == -1 ? depth : leftDepth;
//         int rightDepth = getDepth(root->right, depth+1);
//         rightDepth = rightDepth == -1 ? depth : rightDepth;

//         if (abs(leftDepth - rightDepth) > 1)
//             ans = false;
//         return max(leftDepth, rightDepth);
//     }


//     bool isBalanced(TreeNode* root) {
//         int depth = getDepth(root, 0);
//         return ans;

//     }
// };