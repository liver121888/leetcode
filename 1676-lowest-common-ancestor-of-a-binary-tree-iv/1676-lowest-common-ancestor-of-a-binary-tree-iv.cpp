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

// The lowest common ancestor of a single node is the node itself.
// now we need to consider how does a lca will have
// it will contains all the nodes below it and also including it
// the cnt will be the size of the target
class Solution {
public:

    TreeNode* ans = nullptr;

    int postorder(TreeNode* cur, unordered_set<TreeNode*>& target, int k) {

        if (!cur) 
            return 0;

        int left = postorder(cur->left, target, k);
        int right = postorder(cur->right, target, k);
        int self = target.count(cur) ? 1 : 0;

        int total = left + right + self;

        // 第一次在最深處湊滿 k 個，就是 LCA
        if (total == k && ans == nullptr) 
            ans = cur;
        return total;
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> target(nodes.begin(), nodes.end());
        int k = (int) nodes.size();
        postorder(root, target, k);
        return ans;
    }
};