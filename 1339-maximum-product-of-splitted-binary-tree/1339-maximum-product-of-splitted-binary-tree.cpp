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

// a brute force solution is to separate at every edge and see the product
// time: O(n^2)
// space: O(1)

// we need to calculate where to split the sum and have maximum product
// we can recursively build a sum tree that has the info from left subtree and right subtree

// [1,2,3,4,5,6]
// 1 11 9   2 4 5  3 6 0

// will the max value always happes in the root? not necessnary

//      1
//   2 1 2
//  1 1   1000

// 8000 
// 1003*5


class Solution {
public:

    long long totalSum = 0;
    vector<long long> subTreeSums;

    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        totalSum += root->val;

        int leftSubTreeSum = 0;
        int rightSumTreeSum = 0;
        if (root->left)
            leftSubTreeSum = dfs(root->left);
        if (root->right)
            rightSumTreeSum = dfs(root->right);

        int total = leftSubTreeSum + rightSumTreeSum + root->val;
        subTreeSums.push_back(total);
        return total;
    }

    int maxProduct(TreeNode* root) {

        // dfs traverse to get total sum
        if (!root)
            return -1;

        // get totalSum
        dfs(root);

        // cout << "totalSum: " << totalSum << endl;

        long long maxResult = 0;

        // get possible product and see the max value
        const int m = pow(10, 9) + 7;
        // cout << "subTreeSum: [";
        for (auto subTreeSum : subTreeSums) {
            // cout << subTreeSum << " ";
            long long currResult = (totalSum - subTreeSum) * subTreeSum;
            maxResult = max(maxResult, currResult);
        }
        // cout << "]" << endl;
        return maxResult % m;        
    }
};