/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// can traverse the tree and build a graph
// and find nodes with dist k
// space: O(E) then it's O(n) because E = n - 1
// time: traverse once and bfs: O(n)

// All the values Node.val are unique.

class Solution {
public:

    // implement a hashmap to store parent values
    unordered_map<int, TreeNode*> parents;

    void preorder(TreeNode* root, TreeNode* parentPtr) {

        if (!root)
            return;

        parents[root->val] = parentPtr;

        preorder(root->left, root);
        preorder(root->right, root);

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        preorder(root, nullptr);
        vector<int> ans;
        queue<TreeNode*> bfs;
        unordered_set<int> visited;
        bfs.push(target);
        visited.insert(target->val);
        while (!bfs.empty() && k >= 0) {
            int currLayerSize = bfs.size();
            while (currLayerSize) {

                TreeNode* curr = bfs.front();
                bfs.pop();

                cout << curr->val << endl;

                if (k == 0)
                    ans.push_back(curr->val);

                if (curr->left && visited.find(curr->left->val) == visited.end()) {
                    bfs.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if (curr->right && visited.find(curr->right->val) == visited.end()) {
                    bfs.push(curr->right);
                    visited.insert(curr->right->val);
                }

                TreeNode* p = parents[curr->val];
                if (p && visited.find(p->val) == visited.end()) {
                    bfs.push(p);           
                    visited.insert(p->val);
                }
                currLayerSize--;
            }
            k--;
        }

        return ans;
        
    }
};