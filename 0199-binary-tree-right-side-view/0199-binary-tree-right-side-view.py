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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            // int n = bfs.size();
            // TreeNode* lastNode;
            // for (int i = 0; i < n; i++) {
            //     lastNode = bfs.front();
            //     bfs.pop();
            //     if (lastNode->left)
            //         bfs.push(lastNode->left);
            //     if (lastNode->right)
            //         bfs.push(lastNode->right);                
            // }            
            // res.push_back(lastNode->val);         
            
            // another thought, bfs in different order
            int n = bfs.size();
            res.push_back(bfs.front()->val);
            for (int i = 0; i < n; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                if (node->right)
                    bfs.push(node->right);     
                if (node->left)
                    bfs.push(node->left);
            }         
        }
        return res;
    }
};