
// we can use a sliding window approach
// int l = 0
// int r = 0
// if l == 1, keep increasing r until it's not 1
// if l != 0,  


// Input: nums = [1,1,0,1,1,1]
// Output: 3
// l = 0, r = 0
// l = 0, r = 1
// l = 0, r = 2 -> r++, l = r

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            if (nums[r] == 0) {
                r++;
                l = r;
            } else {
                result = max(result, r - l + 1);
                r++;
            }
        }
        return result;
    }
};