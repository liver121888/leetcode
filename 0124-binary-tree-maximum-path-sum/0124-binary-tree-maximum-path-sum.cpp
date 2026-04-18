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

// we want to maximize the sum on the nodes
// we can think about connecting a node, what's its 
// max contribution
// but when do we start and view the tree?
// first of all, each node itself is a path
// for a node with child, it can decide whether to connect to child

// 從 u 出發，往下延伸，且只能選一邊的最大 path sum
// 可以考慮 path 剛好在 u 這裡轉彎：

// class Solution {
// public:

//     int ans = INT_MIN;

//     int dfs(TreeNode* root) {

//         // cannot return 0
//         // because if a tree is all negative, 
//         // 0 will be max but it's actually 
//         // an empty path
//         // if (!root)
//         //     return;
//         // instead we only dfs when it's valid

//         int leftResult = INT_MIN;
//         int rightResult = INT_MIN;
//         if (root->left)
//             leftResult = dfs(root->left);
//         if (root->right)
//             rightResult = dfs(root->right);

//         // what are some options here?
//         // can pass up
//         // root value itself
//         // root + left
//         // root + right
//         // root + left + right, then we cannot pass this up
//         // but all of these will take max with ans

//         int passResult = root->val;

//         if (leftResult > 0)
//             passResult = max(root->val + leftResult, passResult);

//         if (rightResult > 0)
//             passResult = max(root->val + rightResult, passResult);

//         // check before sum to prevent overflow
//         // we cannot pass this up because the root is the turning point
//         if (leftResult > 0 && rightResult > 0)
//             ans = max(ans, root->val + leftResult + rightResult);

//         ans = max(passResult, ans);
//         // cout << ans << " " << root->val << endl;

//         return passResult;

//     }

//     int maxPathSum(TreeNode* root) {
//         // root is guarantee to exist
//         dfs(root);
//         return ans;
//     }

// };


// class Solution {
// public:
//     int ans = INT_MIN;

//     int dfs(TreeNode* root) {
        
//         if (!root) 
//             return 0;

//         int leftGain = max(0, dfs(root->left));
//         int rightGain = max(0, dfs(root->right));

//         // root 當轉折點
//         ans = max(ans, root->val + leftGain + rightGain);

//         // 回傳給 parent，只能選一邊
//         return root->val + max(leftGain, rightGain);
//     }

//     int maxPathSum(TreeNode* root) {
//         dfs(root);
//         return ans;
//     }
// };

class Solution {
public:

    int ans = INT_MIN/2;

    // recursion
    int dfs(TreeNode* root) {

        // base case
        if (!root)
            return 0;

        // left
        int leftSum = dfs(root->left);
        // right
        int rightSum = dfs(root->right);

        // option 1, ended the path here, cannot pass up this option
        ans = max(ans, leftSum + rightSum + root->val);

        // option 2, you only connect right or left, or just the root
        int result = max(max(leftSum + root->val, rightSum + root->val), root->val);

        ans = max(ans, result);

        return result;

    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;        
    }
};
