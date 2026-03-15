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

// we can do like a inorder traversal to look at the tree
// inorder should be the same of the other inorder

// O(n), traversal
// O(n), save result of traversal

class Solution {
public:

    bool sameTree(TreeNode* a, TreeNode* b) {

        if (!a && !b)
            return true;
        if (!a || !b)
            return false;

        if (a->val != b->val)
            return false;

        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
    }


    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {

    //     queue<TreeNode*> bfs;

    //     bfs.push(root);

    //     while(!bfs.empty()) {
    //         TreeNode* curr = bfs.front();
    //         bfs.pop();

    //         if (sameTree(curr, subRoot))
    //             return true;

    //         if (curr->left)
    //             bfs.push(curr->left);

    //         if (curr->right)
    //             bfs.push(curr->right);
    //     }

    //     return false;        
    // }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // if subtree is a null, any tree can produce this
        if (!subRoot)
            return true;
        // if not root, it's impossible to produce other subtree
        // other than empty tree
        if (!root)
            return false;

        if (sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }




};