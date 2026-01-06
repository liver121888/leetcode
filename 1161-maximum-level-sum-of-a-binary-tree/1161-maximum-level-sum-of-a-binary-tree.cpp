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


// a binary tree
// not bst
// we need to calculate the sum of every level
// we can use bfs to calculate this
// we need to return the level, not the sum
// we have negative value node
// smallest level x such that the sum of all the values of nodes at level x is maximal
// so if same value, don't update

// time complexity: O(n)
// space complexity: O(1)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> bfs;
        bfs.push(root);

        int maxSum = INT_MIN;
        int currLevel = 1;
        int maxLevel = 1;
        while(!bfs.empty()) {
            int numCurrLevelNode = bfs.size();
            int currLevelSum = 0;
            for (int i = 0; i < numCurrLevelNode; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                currLevelSum += node->val;
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
            }
            // update maxSum
            if (currLevelSum > maxSum) {
                maxSum = currLevelSum;
                maxLevel = currLevel;
            }
            currLevel++;
        }        
        return maxLevel;

    }
};