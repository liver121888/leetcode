

// (1)

// 為什麼「path 可以重排成 palindrome」等價於
// pathMask 是 0 或只有一個 bit = 1？

// (2)

// 為什麼 tree 上兩點 path 的奇偶資訊，可以用
// mask[u] ^ mask[v] 得到？

// s consists of only lowercase English letters.

class Solution {
public:
    long long ans = 0;
    vector<vector<pair<int,int>>> graph;
    unordered_map<int, long long> cnt;

    void dfs(int u, int mask) {
        // 找之前有哪些 prefix mask 可以跟目前這個點組成 palindrome path

        // 情況 1: 全部字元都是偶數次
        ans += cnt[mask];

        // 情況 2: 恰好一個字元是奇數次
        for (int b = 0; b < 26; b++) {
            ans += cnt[mask ^ (1 << b)];
        }

        // 把目前這個 mask 放進去，讓後面的點可以配對
        cnt[mask]++;

        // 繼續往下 dfs
        for (auto& [v, ch] : graph[u]) {
            dfs(v, mask ^ (1 << ch));
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        graph.resize(n);

        // 建樹
        for (int i = 1; i < n; i++) {
            int p = parent[i];
            int ch = s[i] - 'a';   // edge (p -> i) 上的字元
            graph[p].push_back({i, ch});
        }

        dfs(0, 0);
        return ans;
    }
};
