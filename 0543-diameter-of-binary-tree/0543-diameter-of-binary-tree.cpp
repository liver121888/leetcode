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


// we need to find the logest path between any two nodes in the tree
// how can this happen
// deepest node on the left and the deepest node on the right
// back to 1, we see the deepest of left subree is 2 right subtree is 1
// 2 + 1 = 3

// if it's
//  1
// /
// 2
// left depth is 1 and right depth is 0
// ans is 1

// root = [1,2,3,4,5]

// 4
// 2 - 2 + 2 - 2 = 0

// 2
// 2 + 2 - 1 - 1 = 2

// 1
// 2 + 1 - 0 - 0 = 3

// root = [1,2]
// 1 + 0 - 0 - 0 = 1


class Solution {
public:

    int ans = 0;

    int dfs(TreeNode* root, int level) {

        if (!root)
            return level-1;

        // left level
        int leftDeepestLevel = dfs(root->left, level+1);

        // right level
        int rightDeepestLevel = dfs(root->right, level+1);

        ans = max(ans, leftDeepestLevel - level + rightDeepestLevel - level);
        return max(leftDeepestLevel, rightDeepestLevel);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        // we dfs to find the depth and sum them
        // recrusively pass the ans and compare

        dfs(root, 0);
        return ans;
    }
};