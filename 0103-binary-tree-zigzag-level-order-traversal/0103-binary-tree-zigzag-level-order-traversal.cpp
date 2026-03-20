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


//  from left to right, then right to left for the next level and alternate between
class Solution {
public:

    // we need to traverse differently for different level parity
    // if even, traverse next from right then left
    // if odd, traverse next from left then right
    // 3 -> 20 then 9
    // 20 -> 
    // [3,9,20,19,18,15,7]
    // [[3],[20,9],[19, 18, 15, 7]]

    // we can have output vector space to save the current layer
    // do normal level order traversal
    // only in certain level we reverse
    // traversal: O(n)
    // space: O(max(num of nodes in a layer)) for the queue

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (!root)
            return ans;


        // do level order traversal
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
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
            if (level % 2 == 1)
                reverse(currLayer.begin(), currLayer.end());
            ans.push_back(currLayer);
            level++;
        }

        return ans;
    }
};