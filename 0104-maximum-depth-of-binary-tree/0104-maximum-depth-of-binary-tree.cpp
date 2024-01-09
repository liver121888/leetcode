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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            int curNodeN = bfs.size();
            for (int i = 0; i < curNodeN; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
            }
            depth++;            
        }
        return depth;        
    }
};