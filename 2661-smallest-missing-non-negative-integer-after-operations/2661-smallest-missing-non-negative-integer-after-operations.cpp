class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        // sequence is not important
        // how to get the maximum
        // we need to filled every positive number including 0

        // [1,-10,7,13,6,8], value = 5
        // [1, 0, 2, 3, 1, 3]

        // 0 1
        // 1 2
        // 2 1
        // 3 2
        // 4 0

        // so ans is 4

        // [1,-10,7,13,6,8], value = 7
        // [1, 3, 0, 6, 6, 1]
        // 0 1
        // 1 2
        // 2 0
        // 3 1
        // 4 0
        // 5 0
        // 6 2

        // so ans is 2

        vector<int> cnts(value);

        for (int i = 0; i < nums.size(); i++) {
            // cnts[abs(nums[i] % value)]++;
            cnts[(nums[i] % value + value) % value]++;

        }

        int mex = 0;
        while (cnts[mex % value] > 0) {
            cnts[mex % value]--;
            mex++;
        }
        return mex;
    }
};