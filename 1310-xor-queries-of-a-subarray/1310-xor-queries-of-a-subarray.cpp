class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        // XOR
        // 0 0 0
        // 1 0 1
        // 0 1 0
        // 1 1 0
        
        int n = arr.size();
        vector<int> prefix_sum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] ^ arr[i];
        }
        
        vector<int> ans;
        for (auto query : queries) {
            int res = prefix_sum[query[1] + 1] ^ prefix_sum[query[0]];
            ans.push_back(res);
        }
        return ans;
    }
};