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


// can simply do bfs traversal
// time: O(n)
// space: O(n) for the queue

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        if (!root)
            return {};

        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<int> ans;
        while (!bfs.empty()) {

            int maxVal = INT_MIN;
            int currLayerSize = bfs.size();
            while (currLayerSize) {
                TreeNode* curr = bfs.front();
                bfs.pop();

                maxVal = max(curr->val, maxVal);
                if (curr->left)
                    bfs.push(curr->left);
                if (curr->right)
                    bfs.push(curr->right);
                currLayerSize--;
            }

            ans.push_back(maxVal);
        }
        return ans;
    }
};