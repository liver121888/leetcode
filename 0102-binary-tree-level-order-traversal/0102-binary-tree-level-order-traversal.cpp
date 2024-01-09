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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            vector<int> level;
            int n = bfs.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curNode = bfs.front();
                bfs.pop();
                level.push_back(curNode->val);                
                if (curNode->left)
                    bfs.push(curNode->left);
                if (curNode->right)
                    bfs.push(curNode->right);
            }            
            ans.push_back(level);
        }
        return ans;
    }
};