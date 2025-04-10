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

    unordered_map<int, int> levels;

    TreeNode* dfs(TreeNode* root, int level) {

        if (!root)
            return nullptr;

        // cout << "root: " << root->val << endl;


        TreeNode* leftLeaf = dfs(root->left, level + 1);
        TreeNode* rightLeaf = dfs(root->right, level + 1);

        // leaves check
        if (!leftLeaf && !rightLeaf) {
            // current root is leaf
            levels[root->val] = level;
            return root;
        }

        // cout << "leftLeaf: " << leftLeaf->val << "rightLeaf: " << rightLeaf->val << endl;

        // leftLeaf is empty or right leaf is empty
        if (!leftLeaf) {
            levels[root->val] = levels[rightLeaf->val];
            return rightLeaf;
        }

        if (!rightLeaf) {
            levels[root->val] = levels[leftLeaf->val];
            return leftLeaf;
        }


        // compare which is deeper
        if (levels[leftLeaf->val] > levels[rightLeaf->val]) {
            levels[root->val] = levels[leftLeaf->val];
            return leftLeaf;
        } else if (levels[leftLeaf->val] < levels[rightLeaf->val]) {
            levels[root->val] = levels[rightLeaf->val];
            return rightLeaf;
        } else {
            levels[root->val] = levels[rightLeaf->val];
            return root;
        }
    }

    // 3 -> 5 -> 6
    // levels[6] = 2
    // 3 -> 5
    // leftLeaf = 6

    // 3 -> 5 -> 2 -> 7
    // levels[7] = 3 
    // 3 -> 5 -> 2 -> 4
    // levels[4] = 3 
    // 3 -> 5 -> 2 
    // both 3, so return 2
    // levels[2] = 4 

    // 3 -> 5
    // levels[6] = 2
    // levels[2] = 4

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        // use level dfs to find the deepest leaves
        // record deepest leaves

        return dfs(root, 0);
    }
};