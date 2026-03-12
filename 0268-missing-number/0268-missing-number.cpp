
// O(n) extra space:
// we can record the things we encouter
// the only thing that we did not encounter is the ans

// Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
// could we sum the whole array
// minus the sum to n

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++)
            sum += i;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
        }
        return sum;
    }
};