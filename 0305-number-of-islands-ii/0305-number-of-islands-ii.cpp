// will disjoint set solve this
// O(k*)

// initially we have n component
// ans n - n = 0
// we have one island -> n - (n-1) = 1
// add a new island, see if it's connected with other island



// class UnionFind {
// private:
//     vector<int> parent, rank;
//     int count;

// public:
//     UnionFind(int size) {
//         // set to -1 for water, pretty clever
//         parent.resize(size, -1);
//         rank.resize(size, 0);
//         count = 0;
//     }

//     void addLand(int x) {
//         // already land
//         if (parent[x] >= 0) 
//             return;
//         parent[x] = x;
//         count++;
//     }

//     bool isLand(int x) {
//         if (parent[x] >= 0) {
//             return true;
//         }
//         return false;
//     }

//     int numberOfIslands() { return count; }

//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     void union_set(int x, int y) {
//         int xset = find(x), yset = find(y);
//         if (xset == yset) {
//             return;
//         }
        
//         if (rank[xset] < rank[yset]) {
//             parent[xset] = yset;
//         } else if (rank[xset] > rank[yset]) {
//             parent[yset] = xset;
//         } else {
//             parent[yset] = xset;
//             rank[xset]++;
//         }
//         count--;
//     }
// };

// class Solution {
// public:
//     vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
//         int x[] = {-1, 1, 0, 0};
//         int y[] = {0, 0, -1, 1};
//         UnionFind dsu(m * n);
//         vector<int> answer;

//         for (auto& position : positions) {
//             int landPosition = position[0] * n + position[1];
//             dsu.addLand(landPosition);

//             for (int i = 0; i < 4; i++) {
//                 int neighborX = position[0] + x[i];
//                 int neighborY = position[1] + y[i];
//                 int neighborPosition = neighborX * n + neighborY;
//                 // If neighborX and neighborY correspond to a point in the grid and there is a land
//                 // at that point, then merge it with the current land.
//                 if (neighborX >= 0 && neighborX < m && neighborY >= 0 && neighborY < n &&
//                     dsu.isLand(neighborPosition)) {
//                     dsu.union_set(landPosition, neighborPosition);
//                 }
//             }
//             answer.push_back(dsu.numberOfIslands());
//         }
//         return answer;
//     }
// };



class DSU {

    int islandCnt;
    vector<bool> grid;
    vector<int> parents;
    vector<int> ranks;

public:
    DSU(int m, int n) {
        islandCnt = 0;
        grid.resize(m*n);
        parents.resize(m*n);
        ranks.resize(m*n);
        for (int i = 0; i < m*n; i++) {
            parents[i] = i;
            ranks[i] = 1;
            grid[i] = false;
        }
    }

    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);

        return parents[x];
    }

    void setGrid(int id) {
        if (getGrid(id))
            return;
        grid[id] = true;
        islandCnt++;
    }

    bool getGrid(int id) {
        return grid[id];
    }

    void unionByRank(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return;

        if (ranks[pa] > ranks[pb]) {
            parents[pb] = parents[pa];
            ranks[pa] += ranks[pb];
        } else {
            parents[pa] = parents[pb];
            ranks[pb] += ranks[pa];
        }
        islandCnt--;
    }

    int getIslandCnt() {
        return islandCnt;
    }

};



class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
        DSU dsu = DSU(m, n);

        const int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        vector<int> ans;
        int k = positions.size();
        ans.resize(k);

        for (int i = 0; i < k; i++) {
            
            int r = positions[i][0];
            int c = positions[i][1];
            int id = r * n + c;

            dsu.setGrid(id);

            for (auto [dy, dx] : dirs) {
                int ny = r + dy;
                int nx = c + dx;

                if (ny < 0 || nx < 0 || ny >=m || nx >= n)
                    continue;

                int nId = ny * n + nx;
                if (dsu.getGrid(nId))
                    dsu.unionByRank(id, nId);
            }
            ans[i] = dsu.getIslandCnt();
        }
        return ans;
    }
};