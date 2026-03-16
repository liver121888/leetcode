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

// to be height balanced
// we find the center as the root
// then we build the left and right
// we do this recursively

// l, r

class Solution {
public:

    // [-10,-3,0,5,9]
    // l = 0, r = 4
    // mid = 2 -> 0

    //       0
    //  -10
    // 0 1
    // mid = 0;

    // [1,2,3,4]
    //      2
    //    1  3
   //          4
   // 
    //     3
    //    1  4
    //     2

    TreeNode* buildTree(const vector<int>& nums, int l, int r) {

        if (l > r)
            return nullptr;

        int mid = (l + r)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid-1);
        root->right = buildTree(nums, mid + 1, r); 

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // height balanced
        return buildTree(nums, 0, nums.size()-1);
    }
};