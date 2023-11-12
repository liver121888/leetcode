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
    
    unordered_map<int, int> m;
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        
        int curMaxMode = 0;
        for (auto& [k, v] : m)
            curMaxMode = max(curMaxMode, v);
        
        vector<int> ans;
        for(auto& [k, v] : m)
            if (v == curMaxMode)
                ans.push_back(k);
        
        return ans;
    }
    
    void traverse(TreeNode* root) {
        if (root == nullptr)
            return;
        int num = root->val;
        if (m.find(num) != m.end())
            m[num] += 1;
        else
            m[num] = 1;
        traverse(root->left);
        traverse(root->right);        
    }
    
    
};