class Solution {
public:

    // 設 DFS 回傳一個 pair：
    // first = 不偷當前 node 的最大值
    // second = 偷當前 node 的最大值
    pair<int, int> dfs(TreeNode* node) {
        // {notRob, rob}
        if (!node)
            return {0, 0};

        // {notRobL, robL}
        auto left = dfs(node->left);
        // {notRobR, robR}
        auto right = dfs(node->right);

        // 如果不偷當前node
        // 要不要偷下面都可以！
        // 不要想說greedy然後偷了下面導致錯失global max
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        int rob = node->val + left.first + right.first;

        return {notRob, rob};
    }

    int rob(TreeNode* root) {
        // 為什麽只要call root?
        // 因為只能從root進入
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};