
// Return true if the edges of the given graph make up a valid tree, and false otherwise.
// what is a tree
// n nodes -> have exactly n-1 edge
// no cycle

// There are no self-loops or repeated edges.

// one way to do this is to union find and see if there is only one component
// we can also build adjLists, dfs traverse

// to me it's straightforward to use dsu

// n nodes labeled from 0 to n - 1

// 1 - 0 - 4
//   2 - 3


class DSU {

public:
    vector<int> parents;
    vector<int> ranks;

    DSU(int n) {
        parents.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            ranks[i] = 1;
        }
    }
    
    int findParent(int i) {
        if (parents[i] != i)
            parents[i] = findParent(parents[i]);

        return parents[i];
    }

    bool unionByRank(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb)
            return false;
        
        if (ranks[pa] >= pb) {
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
    bool validTree(int n, vector<vector<int>>& edges) {

        // if (edges.size() >= n || edges.size() < n - 1)
        //     return false;

        if (edges.size() != n - 1)
            return false;


        DSU dsu(n);

        for (const auto edge : edges) {
            // 如果遭遇任何一個不能union by rank的話
            // 代表最後一定沒辦法全部連起來
            // 所以false
            if (!dsu.unionByRank(edge[0], edge[1]))
                return false;
        }

        return true;
    }
};