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

// we bfs
// one go to the left
// one go to the right 


class Solution {
public:

    // recursive
    // bool isMirror(TreeNode* t1, TreeNode* t2) {
    //     if (!t1 && !t2)
    //         return true;
    //     if (!t1 || !t2)
    //         return false;

    //     if (t1->val != t2->val)
    //         return false; 

    //     return isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);

    // }
    // bool isSymmetric(TreeNode* root) {
    //     return isMirror(root, root);
    // }
    
    // iterative
    bool isSymmetric(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* leftNode = q.front();
            q.pop();
            TreeNode* rightNode = q.front();
            q.pop();

            if (!leftNode && !rightNode)
                continue;

            if (!leftNode || !rightNode)
                return false;

                
            if (leftNode->val != rightNode->val)
                return false;

            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);

        }
        return true;
    }



};