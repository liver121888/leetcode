
// constraints
// gird[i][j] >= 1
// the grid is valid

// add or substract on any number is possible
// how can we find the target univalue

// final sum = m * n * v 
// curr sum = y

// m * n * v = y + x * c
// v = (y + x * c) / m*n

// grid = [[2,4],[6,8]], x = 2
// 20
// 4 * v

// it is impossible to make two integers a and b equal if they 
// have different remainders dividing by x

// sort
// binarysearch to find the value


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums(m*n);
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums[i*n + j] = grid[i][j];
            }
        }

        // In C++, we can avoid fully sorting the array by using the nth_element 
        // function. This operation runs in linear time and ensures that the desired 
        // element is placed at the index it would occupy in a fully sorted array. 
        // For the median, this means the element will be placed at the middle index.
        nth_element(nums.begin(), nums.begin() + m*n/2, nums.end());
        // sort(nums.begin(), nums.end());
        int finalCommonNumber = nums[m*n/2];

        for (int number : nums) {
            // If the remainder when divided by x is different for any number,
            // return -1
            if (number % x != finalCommonNumber % x)
                return -1;
            // Add the number of operations required to make the current number
            // equal to finalCommonNumber
            result += abs(finalCommonNumber - number) / x;
        }
        return result;

    }
};