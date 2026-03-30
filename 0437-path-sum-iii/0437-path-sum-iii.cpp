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

// there can also be negative numbers
// it has to go down
// brute force
// start at every node
// 10 -> n
// 5 -> log(n)
// 3 -> log(log(n))
// total: n + .... 


// what are some repeat calculation here
// prefixSum the current path
// when we reach the leaves, we can calculate the number 
// of subarray that sums up to targetSum


class Solution {
public:

    int ans = 0;
    int target;

    // <1 2 3 4 5>
    // 0 10 15 18 21

    // 10 -> 5 -> 3 -> 3 and -2
    // how to prevent recalculate

    // void calculatePrefix(const vector<int>& v) {

    //     for (int i = 0; i < v.size(); i++) {
    //         for (int j = i+1; j < v.size(); j++) {
    //             if (v[j] - v[i] == target) {
    //                 cout << i << " " << j << endl;
    //                 ++ans;
    //             }
    //         }
    //     }

    // }

    // 0, 10, 15, 18 21
    // currSum - hisSUm = target

    void preorder(TreeNode* root, unordered_map<long long,int>& freq, long long currSum, int targetSum) {

        if (!root)
            return;

        currSum += root->val;
        // cout << currSum << endl;
        // cout << "freq: [";
        // for (const auto& [s, cnt] : freq) {
        //     cout << s << "/" << cnt << " ";
        // }
        // cout << "]" << endl;

        if (freq.find(currSum - targetSum) != freq.end())
            ans += freq.at(currSum - targetSum);

        // change state
        freq[currSum]++;

        // state.push_back(currSum);

        // we don't care about leaves or not
        // if (!root->left && !root->right) {
        //     // cout << root->val << endl;
        //     calculatePrefix(state);
        // } else {
        preorder(root->left, freq, currSum, targetSum);
        preorder(root->right, freq, currSum, targetSum);
        // }
        freq[currSum]--;
        // state.pop_back();

    }

    // exactly Subarray Sum Equals K tree version
    int pathSum(TreeNode* root, int targetSum) {

        // vector<int> state = {0};
        unordered_map<long long, int> freq;
        freq[0] = 1;
        preorder(root, freq, 0, targetSum);
        return ans;
    }
};