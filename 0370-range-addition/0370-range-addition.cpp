class Solution {
public:

    // mark range operation
    // Example 1:
    // Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
    // Output: [-2,0,3,5,3]

    // [-2,2,3,2,-2]

    // [-2, 0, 3, 5 3]


    // Example 2:
    // Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
    // Output: [0,-4,2,2,2,4,4,-4,-4,-4]


    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

        // map<int, int> memo;

        vector<int> ans(length);

        for (const auto& update : updates) {
            int start = update[0];
            int end = update[1];
            int inc = update[2];

            ans[start] += inc;
            if (end+1 < length)
                ans[end+1] -= inc;

        }

        int runningSum = 0;
        for (int i = 0; i < length; i++) {
            runningSum += ans[i];
            ans[i] = runningSum;
        }

        return ans;
        
    }



};