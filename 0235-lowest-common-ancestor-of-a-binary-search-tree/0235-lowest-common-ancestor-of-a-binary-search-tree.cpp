/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// find LCA, post order traversal
// but a bst
// we have two nodes we need to find
// so when the curr root > p root > q
// we need to search the left part
// if root < p root > q

// when we dfs find the node the first one is goann be the lowerest
// 

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int parentVal = root->val;

        // Value of p
        int pVal = p->val;

        // Value of q;
        int qVal = q->val;

        if (pVal > parentVal && qVal > parentVal) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (pVal < parentVal && qVal < parentVal) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // We have found the split point, i.e. the LCA node.
        return root;

    }
};
