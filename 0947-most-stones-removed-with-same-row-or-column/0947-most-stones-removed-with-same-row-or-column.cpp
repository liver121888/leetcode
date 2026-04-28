
// dsu
// we can connect if they share the same row or column
// and see what's left

// each stone starts with it's own group
// we traverse and see if we can union
// time: O(n^2 * O(a)) because we need to traverse, O(a) ~ O(1)
// space: O(n)

class DSU {

    vector<int> ranks;
    vector<int> parents;
    int numGroup;

public:

    DSU(int n) {
        ranks.resize(n);
        parents.resize(n);
        numGroup = n;
        for (int i = 0; i < n; i++) {
            ranks[i] = 1;
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        numGroup--;
        // put larger rank to smaller rank
        if (ranks[pa] < ranks[pb]) {
            parents[pb] = parents[pa];
        } else {
            parents[pa] = parents[pb];
        }

    }

    int getNumGroup() {
        return numGroup;
    }

};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        DSU dsu = DSU(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    dsu.unionByRank(i, j);
            }
        }

        return n - dsu.getNumGroup();
        
    }
};