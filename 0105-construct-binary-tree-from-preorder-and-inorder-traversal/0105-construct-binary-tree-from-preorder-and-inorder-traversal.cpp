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

// preorder and inorder of the same tree
// preorder will go from root->left->right
// inorder left->root->right
// build the tree recursively
// we take the element in preorder will tell us which one is the root
// 3 9 20 15 7
// 3 is the root -> we serach it in the inorder
// we can divide the tree to left subtree and right subtree
// [9] [15 20 7]
// go into the left subtree, because we also know the next element in preorder is 9
// so 9 is the left subtree root
// 20 is the right subree root
// again we divid
// [15] [7]
// preorder tell use the left subtree root

//    3
//   / 
//  9

// -1 1 -> return nullptr
//  20 -> 3
// 2, 4
// 15 -> 2
// 1 3, need to prevent from traverse the 2 and 3
// we can mark visited in place using the preorder -> mark as -4000
// visited we don't travese


// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
// };

// we need the range of the left, right subtree in inorder
// we also need root ptr, the idx in preporder

// currIdx is for preorder

// indexes for inorder
// l
// r

// lIdx is where left subtree ends
// rIdx is where right subtree starts
// TreeNode* helper(inorder, preorder, lIdx, rIdx) {



//     build the root
//     find the midIdx in inorder by seraching in the v/idx map we build
//     currIdx always increaes by one as we get deeper
//     midIdx

//     TreeNode* l = helper(inorder, preorder, midIdx - 1, midIdx+1);
//     TreeNode* r = helper()

//     connect root to l and right
//     return root
// }

class Solution {
public:

    int preorderIdx = 0;

    TreeNode* dfs(const vector<int>& preorder, 
        const vector<int>& inorder, 
        const unordered_map<int,int>& val2InorderIdx,
        int l, int r) {

        if (l > r)
            return nullptr;
        int rootVal = preorder[preorderIdx];
        preorderIdx++;
        TreeNode* root = new TreeNode(rootVal);
        int i = val2InorderIdx.at(rootVal);
        root->left = dfs(preorder,inorder,val2InorderIdx, l, i-1);
        root->right = dfs(preorder,inorder,val2InorderIdx, i+1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = inorder.size();
        unordered_map<int, int> val2InorderIdx;
        for(int i = 0; i < n; i++){
            val2InorderIdx[inorder[i]] = i;
        }

        TreeNode* root = dfs(preorder, inorder, val2InorderIdx, 0, n-1);
        return root;
    }


};