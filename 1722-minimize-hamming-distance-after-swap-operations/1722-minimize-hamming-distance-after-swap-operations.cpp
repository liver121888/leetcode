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

    // The Hamming distance of two arrays of the same length, 
    // source and target, is the number of positions where the elements 
    // are different. Formally, it is the number of indices i for 0 <= i <= n-1 
    // where source[i] != target[i] (0-indexed).

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
        // this stores, in this index's connected component,
        // the occur frequency of a number
        unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            // find the component
            int f = find(i);
            // increment the freqency of this number in this component
            sets[f][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f].find(target[i]) != sets[f].end()) {
                if (sets[f][target[i]] > 0)
                    sets[f][target[i]]--;
                else {
                    ans++;
                }
            } else {
                ans++;
            }
        }
        return ans;
    }
};
