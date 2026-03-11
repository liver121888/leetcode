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

// we need to return the edge numbers as distance
// we can do an inorder traversal
// if at certain node we find the p or q
// we return p or q
// if at a node we find both, we calculate the distance
// if didn't find anything, we return null

// Am I the only person that just converted the tree to a graph and just went from p -> q?

class Solution {
public:


    int ans = 0;
    int p_;
    int q_;

    // Function to find the lca of two nodes recursively.
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (root == nullptr or root->val == p or root->val == q) {
            return root;
        }
        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);
        if (left != nullptr and right != nullptr) {
            return root;
        }
        return (left != nullptr) ? left : right;
    }


    int findDistance(TreeNode* root, int p, int q) {
        
        TreeNode* lca = findLCA(root, p, q);

        // Start the BFS process with lca as the root.
        queue<TreeNode*> bfs;
        bfs.push(lca);

        // search both at the same time
        int distance = 0, depth = 0;
        bool foundp = 0, foundq = 0;
        while (!bfs.empty() or (foundp == 0 and foundq == 0)) {
            int size = bfs.size();

            // Traverse all nodes at the height level.
            while (size--) {
                TreeNode* front = bfs.front();
                bfs.pop();
                // Add the current height to the distance if p or q is found.
                if (front->val == p) {
                    distance += depth;
                    foundp = 1;
                }
                if (front->val == q) {
                    distance += depth;
                    foundq = 1;
                }
                // Add the children to the queue. These will be traversed in the
                // next height level.
                if (front->left != nullptr) {
                    bfs.push(front->left);
                }
                if (front->right != nullptr) {
                    bfs.push(front->right);
                }
            }
            depth++;
        }

        return distance;

    }
};