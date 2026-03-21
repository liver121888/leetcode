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

// Return the longest ZigZag path contained in that tree.
// we can do a backtracking to see every possibilities
// time: O(2^n), where n is the number of the nodes
// number of nodes visited - 1. (A single node has a length of 0).

// we can also do a dp solution and use some extra space
// dp[node] -> save the longest zigzag path
// dp[node] = max(dp[node->right], dp[node->left])
// dp[root] = max(dp[node->right], dp[node->left])


// actually we don't need to dp because the path is confined
// from root go left or right and check which one is deeper
// because the deepest path is always happens on the root
// this is wrong, because we can find the example that the longest path
// exist on the middle of the tree

// we can dfs and keep a ans
// always max the ans

class Solution {
public:
    int ans = 0;

    // return {leftLen, rightLen}
    // leftLen:  from this node, first go left
    // rightLen: from this node, first go right
    pair<int, int> dfs(TreeNode* node) {
        if (!node)
            return {-1, -1};

        auto [leftLeft, leftRight] = dfs(node->left);
        auto [rightLeft, rightRight] = dfs(node->right);

        int goLeft = leftRight + 1;   // node -> left -> right -> ...
        int goRight = rightLeft + 1;  // node -> right -> left -> ...

        ans = max(ans, max(goLeft, goRight));

        return {goLeft, goRight};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};