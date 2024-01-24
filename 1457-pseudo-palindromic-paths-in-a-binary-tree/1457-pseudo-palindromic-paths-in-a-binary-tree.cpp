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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> curState(10, 0);
        return dfs(root, curState);
    }
    
    int dfs(TreeNode* root, vector<int>& curState) {
        if (!root)
            return 0; 
        
        curState[root->val]++;
        
        vector<int> tempState = curState;
        
        // at leaves
        if (!root->left && !root->right) {
            bool once = false;
            for (auto cnt : curState) {
                if (cnt % 2 == 1) {
                    if (!once)
                        once = true;
                    else
                        return 0;                    
                }                
            }
            return 1;
        }     
        
        // not leaves
        int left = dfs(root->left, tempState);
        int right = dfs(root->right, curState);        
        
        // passing
        return left + right;
    }
    
};