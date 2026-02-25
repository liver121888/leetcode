#include <bits/stdc++.h>
using namespace std;

// 我會用「線性公式 + 反向依賴圖」做，這題最精簡、專業、而且更新是 局部傳遞（不用每次掃全表）。
// 核心想法：
// 每個 cell 存：
// val：目前值
// refs：這格若是公式，引用了哪些 cell（含 multiplicity 次數，即這個cell被引用了幾次）
// 再存一張 反向圖 rev[u] = { 所有依賴 u 的 cell }
// 當某格被 set 或 sum 改變時，算出 delta = newVal - oldVal，用 BFS/queue 把 delta 沿著反向圖傳遞：
// 若 d 依賴 u 且係數是 k = d.refs[u]，則 d.val += delta * k
// 因為題目保證沒有環，線性傳遞就完事。
// 下面是我會寫的 C++（精簡、LeetCode 風格、可直接交）：

class Excel {
    struct Cell {
        int val = 0;
        unordered_map<int,int> refs; // referenced cellId -> count
    };

    int H, W;
    vector<Cell> cells;
    vector<unordered_set<int>> rev; // rev[u] = all cells that depend on u

    int id(int r, int c) const { return r * W + c; } // r,c are 0-based

    // supports "A1" (single letter column per LC631)
    pair<int,int> parseCell(const string& s) {
        int c = s[0] - 'A';
        int r = stoi(s.substr(1)) - 1;
        return {r, c};
    }

    unordered_map<int,int> parseNumbers(const vector<string>& nums) {
        unordered_map<int,int> m;
        for (auto &t : nums) {
            auto pos = t.find(':');
            if (pos == string::npos) {
                auto [r,c] = parseCell(t);
                m[id(r,c)]++;
            } else {
                auto [r1,c1] = parseCell(t.substr(0,pos));
                auto [r2,c2] = parseCell(t.substr(pos+1));
                for (int r = r1; r <= r2; r++)
                    for (int c = c1; c <= c2; c++)
                        m[id(r,c)]++;
            }
        }
        return m;
    }

    int eval(const unordered_map<int,int>& refs) {
        long long s = 0;
        for (auto &[u, k] : refs) s += 1LL * cells[u].val * k;
        return (int)s;
    }

    void removeOldFormulaEdges(int v) {
        for (auto &[u, k] : cells[v].refs) rev[u].erase(v);
        cells[v].refs.clear();
    }

    void addFormulaEdges(int v, const unordered_map<int,int>& refs) {
        for (auto &[u, k] : refs) rev[u].insert(v);
        cells[v].refs = refs;
    }

    void propagate(int start, int delta) {
        if (delta == 0) return;
        queue<pair<int,int>> q;
        q.push({start, delta});
        while (!q.empty()) {
            auto [u, du] = q.front(); q.pop();
            for (int v : rev[u]) {
                auto it = cells[v].refs.find(u);
                if (it == cells[v].refs.end()) continue;
                int dv = du * it->second;
                cells[v].val += dv;
                q.push({v, dv});
            }
        }
    }

public:
    Excel(int height, char width) : H(height), W(width - 'A' + 1) {
        cells.assign(H * W, Cell{});
        rev.assign(H * W, {});
    }

    void set(int r, char c, int val) {
        int v = id(r-1, c-'A');
        int old = cells[v].val;

        removeOldFormulaEdges(v);     // overwrite -> formula gone
        cells[v].val = val;

        propagate(v, val - old);
    }

    int get(int r, char c) {
        return cells[id(r-1, c-'A')].val;
    }

    int sum(int r, char c, vector<string> nums) {
        int v = id(r-1, c-'A');
        int old = cells[v].val;

        auto refs = parseNumbers(nums);
        int newVal = eval(refs);

        removeOldFormulaEdges(v);
        addFormulaEdges(v, refs);
        cells[v].val = newVal;

        propagate(v, newVal - old);
        return newVal;
    }
};