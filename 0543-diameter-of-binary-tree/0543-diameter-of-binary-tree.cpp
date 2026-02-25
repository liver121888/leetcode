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

// the deepest node in the left and the deepest node in the right 
// we can have an ans check in every node
// in every node, we take the deepest node on left and deepest on right
// calculate their distance

class Solution {
public:

    int ans = 0;
    int calculateDist(TreeNode* root) {

        if (!root)
            return 0;
        
        int leftDist = calculateDist(root->left);
        int rightDist = calculateDist(root->right);

        // cout << root->val << " " << leftDist << " " << rightDist << endl;

        ans = max(ans, leftDist + rightDist + 1);
        return 1 + max(leftDist, rightDist);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calculateDist(root);
        // by the number of edges between them
        // ans is the number of nodes
        return ans - 1;
    }
};