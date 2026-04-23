class Solution {
public:
    vector<int> parents;
    vector<int> rank;

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

        if (rank[pa] <= rank[pb]) {
            parents[pa] = pb;
            rank[pb] += rank[pa];
        } else {
            parents[pb] = pa;
            rank[pa] += rank[pb];
        }
    }



    int minimumHammingDistance(vector<int>& source, 
        vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        parents.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parents[i] = i;

        for (const auto& swap : allowedSwaps) {
            unionByRank(swap[0], swap[1]);
        }

        // Additionally, we use a hash table to record the frequency of 
        // each element within every set.
        unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};