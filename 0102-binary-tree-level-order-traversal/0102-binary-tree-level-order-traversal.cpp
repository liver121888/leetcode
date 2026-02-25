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


// bfs each layer
// time: O(n)
// space: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currLayerSize = q.size();
            vector<int> currLayer;
            while (currLayerSize) {
                TreeNode* curr = q.front();
                q.pop();
                currLayer.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                currLayerSize--;
            }
            ans.push_back(currLayer);
        }
        return ans;
    }
};