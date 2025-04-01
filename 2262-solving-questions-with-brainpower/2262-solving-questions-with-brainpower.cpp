class Solution {
public:
    // [[1,1],[2,2],[3,3],[4,4],[5,5]]
    // [2, 2] [5, 5] -> 7


    long long dfs(const vector<vector<int>>& questions, vector<long long>& dp, int currIdx) {

        // base case
        if (currIdx >= questions.size())
            return 0;

        if (dp[currIdx] != -1)
            return dp[currIdx];

        int points = questions[currIdx][0];
        int brainpower = questions[currIdx][1];

        // two options
        // solve this problem
        long long option1 = points + dfs(questions, dp, currIdx + brainpower + 1);

        // not to solve this problem
        long long option2 = dfs(questions, dp, currIdx + 1);

        // cout << "idx: " << currIdx << " option1: " << option1 << " option2: " << option2 << endl;

        dp[currIdx] = max(option1, option2);

        // return the max
        return dp[currIdx];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // store currIdx answer
        // vector<long long> dp(questions.size(), -1);
        // return dfs(questions, dp, 0);

        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 < n) {
                dp[i] += dp[i + skip + 1];
            }
            
            // dp[i] = max(solve it, skip it)
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];


    }
};