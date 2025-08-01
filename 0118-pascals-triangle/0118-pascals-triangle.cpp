class Solution {
public:

    // 0 -> 1
    // 1 -> 2
    // 2 -> 3
    // 3 -> 4
    // 4 -> 5

    vector<vector<int>> result;

    void calculate(vector<int> prev, int curr, int target) {

        // base case
        if (curr == target)
            return;

        vector<int> currLayer = vector<int>();
        currLayer.push_back(1);

        for (int i = 1; i < prev.size(); i++) {
            currLayer.push_back(prev[i - 1] + prev[i]);
        }
        currLayer.push_back(1);

        result.push_back(currLayer);

        calculate(currLayer, curr+1, target);
    }


    vector<vector<int>> generate(int numRows) {

        // the two sides are alwyas gonna be 1

        vector<int> init = {1};
        result.push_back(init);
        calculate(init, 1, numRows);
        return result;
    }
};