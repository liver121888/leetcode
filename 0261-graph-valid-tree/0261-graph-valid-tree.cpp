
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
    int numComponents;

    DSU(int n): numComponents(n) {
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

    void unionByRank(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb)
            return;
        
        if (ranks[pa] >= pb) {
            parents[pb] = pa;
            ranks[pa] += ranks[pb];
        } else {
            parents[pa] = pb;
            ranks[pb] += ranks[pa];
        }
        numComponents--;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() >= n || edges.size() < n - 1)
            return false;


        DSU dsu(n);

        for (const auto edge : edges) {
            dsu.unionByRank(edge[0], edge[1]);
        }

        return dsu.numComponents == 1;
    }
};