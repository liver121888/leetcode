class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // vector(n^2)
        // for each index 
        // true
        // if true -> a
        // iter array: false -> b
        // time O(n^2)
        // space O(n^2)

        // grid normal -> sum = 1 + .. + n^2 = s
        // grid unormal -> sum = s - b + a = s'
        // a -> b
        // b = s - s' + a

        int n = grid.size();
        vector<bool> seen(n*n);
        int a;

        int normalSum = n*n * (n*n + 1) / 2;
        int curSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                curSum += val;
                bool saw = seen[val - 1];
                if (!saw)
                    seen[val - 1] = true;
                else
                    a = val;
            }
        }
        cout << "n: " << normalSum << " cur: " << curSum << endl;
        return {a, normalSum - curSum + a};
    }
};