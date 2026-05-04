// nums.size() should be within int?
// nums[i], is there constraint?
// will there be negative number?
// yes
// will there be empty nums?
// maybe
// k ranges from 0 to n-1
// we need to find the max of F(k)
// brute-force:
// O(n * n) n possibilities each test takes n to sum up
// space: O(n)

// Example 1:
// Input: nums = [4,3,2,6]
// Output: 26
// Explanation:
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
// F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
// So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
// Example 2:

// Input: nums = [100]
// Output: 0

// F function is index*element
// no greedy because we need the entire sum and we cannot modify the sequence
// after we calculate one sum, can we roll it to another?
// F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
// F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
// F(i + 1) = F(i) - (n-1)*F(i)[n-1] + 1*F(i)[0] + middleSum
// F(i + 1) = middleSum + F(i)[n-1]

// totalSum = 15
// weightSum = 25
// result = 25

// 40 - 18 + 4
// 16
// [6, 4,3,2]

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n = nums.size();
        if (n <= 1)
            return 0;

        // long long totalSum = accumulate(nums.begin(), nums.end(), 0);
        // specify 0LL to prevent overflow
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long weightedSum = 0;
        // O(n)
        for (int i = 0; i < n; i++) {
            // might overflow
            // weightedSum += i * nums[i];
            weightedSum += 1LL * i * nums[i];
        }

        long long result = weightedSum;

        // cout << weightedSum << " " << totalSum << endl;

        // at least size 2
        // O(n)
        for (int i = n-1; i > 0; i--) {

            int lastNum = nums[i];

            weightedSum = weightedSum + totalSum - lastNum*n;
            // cout << firstNum << " " << lastNum << " " << weightedSum << endl;
            result = max(result, weightedSum);
        }

        return result;
    }
};

// dp idea
// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int f = 0, n = nums.size();
//         int numSum = accumulate(nums.begin(), nums.end(), 0);
//         for (int i = 0; i < n; i++) {
//             f += i * nums[i];
//         }
//         int res = f;
//         for (int i = n - 1; i > 0; i--) {
//             f += numSum - n * nums[i];
//             res = max(res, f);
//         }
//         return res;
//     }
// };