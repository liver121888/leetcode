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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leavesSeq1;
        traverse(root1, leavesSeq1);
        vector<int> leavesSeq2;
        traverse(root2, leavesSeq2); 
        if (leavesSeq1.size() != leavesSeq2.size())
            return false;    
        for (int i = 0; i < leavesSeq1.size(); i++) {
            if (leavesSeq1[i] != leavesSeq2[i])
                return false;
        }
        return true;
    }
    
    bool traverse(TreeNode* root, vector<int>& leavesSeq) {
        if (!root)
            return true;
        // cout << root->val << endl;
        bool isLeftEmpty = traverse(root->left, leavesSeq);
        bool isRightEmpty = traverse(root->right, leavesSeq);
        if (isLeftEmpty && isRightEmpty)
            leavesSeq.push_back(root->val);
        return false;        
    }
};