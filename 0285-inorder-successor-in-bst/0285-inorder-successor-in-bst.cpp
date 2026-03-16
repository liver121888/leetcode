/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 比 p 大的最小那個節點
// inorder
// it's like binary search


// [6,null,8,7,9]

// 因為 BST 的 inorder 是 sorted order，所以 successor 等價於找比 p 大的最小節點。
// 若目前節點大於 p，它可能是答案，但左子樹也許有更小的合法答案，所以記下後往左。
// 若目前節點小於等於 p，它不可能是答案，所以往右。
// 想想看哪裡可能是答案


class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        TreeNode* succ = nullptr;
        TreeNode* cur = root;

        // it's like binary search
        // save the possible range and everytime shrink

        while (cur) {
            if (p->val < cur->val) {
                // cur 可能是答案
                // 然後往哪走？
                succ = cur;
                cur = cur->left;
            } else {
                // cur 不可能是答案
                // 往哪走？
                cur = cur->right;
            }
        }

        return succ;
    }

};