class Solution {
public:
    // have the digit sum
    // O(n * k), k is the num of digit

    // edge case: []

    int digitSum(int x) {
        int result = 0;
        while (x) {
            result += x % 10;
            x /= 10;
        }
        return result;
    }

    int minElement(vector<int>& nums) {

        int minSum = INT_MAX;
        for (int num : nums) {
            minSum = min(minSum, digitSum(num));
        }
        return minSum;
    }
};