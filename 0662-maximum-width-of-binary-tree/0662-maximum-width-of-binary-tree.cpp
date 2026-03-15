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

// queue to bfs the entire tree
// we also need to put in null nodes at first
// because it also contibutes to the width of a tree
// check whether we have a node to enclose the null nodes
// to have the correct width

// tree has a depth of d
// the maximum width is w
// n nodes in the tree
// time O(n)
// space O(w)

class Solution {
public:

//      0
//    1          2
//  3   4     5     6
// 7 8 9 10 11 12 13 14

// 1
// 2
// 4
// 8

// 13 - 7 + 1 = 7

// level
// when push in a child
// we only care about it's id 

    int widthOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();
            long long offset = q.front().second;  // normalization base

            long long first, last;

            for (int i = 0; i < size; i++) {

                auto [node, id] = q.front();
                q.pop();

                id -= offset;  // normalize

                if (i == 0) first = id;
                if (i == size - 1) last = id;

                if (node->left)
                    q.push({node->left, 2 * id});

                if (node->right)
                    q.push({node->right, 2 * id + 1});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }

};