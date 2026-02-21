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
    // inroder val -> idx
    unordered_map<int,int> inorderIds;
    int preorderIdx;
    int n;

    // r is the idx that inclusively right tree ends
    // l is the idx that inclusively left tree begin
    // mid is the one that divide it
    TreeNode* helper(const vector<int>& preorder, vector<int>& inorder, int l, int r) {

        // cout << preorderIdx << endl;        
        if (l > r)
            return nullptr;

        int preorderVal = preorder[preorderIdx];
        TreeNode* root = new TreeNode(preorderVal);
        preorderIdx++;

        int midIdx = inorderIds[preorderVal];

        TreeNode* lNode = helper(preorder, inorder, l, midIdx-1);
        TreeNode* rNode = helper(preorder, inorder, midIdx+1, r);

        root->left = lNode;
        root->right = rNode;

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorderIds[inorder[i]] = i;
        }

        // cnt for which root
        preorderIdx = 0;
        TreeNode* head = helper(preorder, inorder, 0, n-1);
        return head;
    }
};