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

        auto currQ = questions[currIdx];
        int points = currQ[0];
        int brainpower = currQ[1];

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
        vector<long long> dp(questions.size(), -1);
        return dfs(questions, dp, 0);
    }
};