
//  there could be multiple valid connections between the 
// same two houses with different costs.
// Return the minimum total cost to supply water to all houses.

// so for each connected component, we only choose the smallest
// cost to build the well there, and pipe it to other nodes
// for pipes, we only choose the minimum cost
// for single nodes that has no edge, we have no choice but to 
// build the wells

// can we use disjoint set to find the minimum cost house in a 
// connected component
// don't over complicate
// we can build adjLists with the smallest cost

// what if we use kruskal
// disjoint set to know what are some componenets
// when union, we choose the one we smallest well value

// we also need to build adjlist with smallest cost between the houses
// and traverse to know the cost

// V nodes, E unique edges
// time: O(V + E)
// space: O(V + e)

// 你的原本思路哪裡卡住
// 你現在在想：
// 先用 DSU 找 connected component
// 每個 component 選一個最便宜的井
// 再加 pipe 成本
// 這裡有一個根本問題：
// 不是每個 connected component 都要整個接起來

// 最強思路
// 把挖井也變成邊，然後直接做 MST
// 正解 1：Kruskal + 虛擬節點
// 如何想到？
// 想想每一家有哪些選擇
// 自然會想到要include自己挖井
class DSU {

    vector<int> parents;
    vector<int> ranks;
public:
    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    bool uniteByRank(int a, int b) {

        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return false;

        if (ranks[pa] <= ranks[pb]) {
            parents[pb] = pa;
            ranks[pa] += ranks[pb];
        } else {
            parents[pa] = pb;
            ranks[pb] += ranks[pa];
        }
        return true;
    }
};

class Solution {
public:

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    
        vector<vector<int>> edges;

        // virtual node 0 -> house i, node 0即是挖井的成本
        // 把他想成虛擬水源
        for (int i = 1; i <= n; i++) {
            edges.push_back({wells[i - 1], 0, i});
        }

        // pipe edges
        for (const auto& p : pipes) {
            // cost 放前面sort
            edges.push_back({p[2], p[0], p[1]});
        }

        // sort 由小排到大
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        // include virtual node
        DSU dsu = DSU(n+1);

        int ans = 0;
        // kruskal
        for (auto& e : edges) {
            int cost = e[0];
            int u = e[1];
            int v = e[2];
            // if success unite, add edge to ans
            if (dsu.uniteByRank(u, v)) {
                ans += cost;
            }
        }

        return ans;
    
    }
};



// class Solution {
// public:

//     int bfsCost(const DSU& dsu, const vector<int>& wells, const vector<vector<int>>& adjMatrix, 
//         unordered_set<int>& visited, int source) {

//         int result = 0;

//         if (visited.find(source) != visited.end())
//             return result;

//         result += wells[dsu.find(source)];

//         queue<int> q;
//         q.push(source);

//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();

//             for (const adjMatrix[q]

//         }


//     }



//     int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
//         DSU dsu = DSU();

//         // pipes are 1 indexed
//         vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX/2));
//         for (const auto& pipe : pipes) {
//             adjMatrix[pipe[0]-1][pipe[1]-1] = min(adjMatrix[pipe[0]-1][pipe[1]-1], pipe[2]);
//             adjMatrix[pipe[1]-1][pipe[0]-1] = min(adjMatrix[pipe[1]-1][pipe[0]-1], pipe[2]);
//             dsu.uniteByCost(pipe[0]-1, pipe[1]-1);
//         }

//         int ans = 0;
//         unordered_set<int> visited;
//         for (int i = 0; i < n; i++) {
//             ans += bfsCost(dsu, wells, adjMatrix, visited, i);
//         }
//         return ans;

//     }
// };