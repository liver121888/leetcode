// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
// unsorted
// we start checking from 0
// then 1, 2, 3 ....
// can be negative numbers

// if we have unordered_set
// O(n) space but we can quickly know what's missing
// can we use the vector itself as the unordered_set?
// we look for 1
// if we found 1, we put it on index 1?

// ok, we can filled the positive number from the back
// and the swaping
// we have two pointers
// if we find a non-positive number
// we throw it to the back, and decrement until we find a positive number
// if the number is positive, we put it in the front
// so all the positive number is in the front
// O(2n) = O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        bool containsOne = false;
        int n = nums.size();

        // clever, we need to check of n also
        for (auto& num : nums) {
            if (num == 1)
                containsOne = true;
            else if (num <= 0 || num > n)
                num = 1;
        }

        if (!containsOne)
            return 1;

        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);
            // use 0 as the n counter
            if (value == n) {
                nums[0] = -abs(nums[0]);
            } else {
                nums[value] = -abs(nums[value]);
            }
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] > 0)
                return i;
        }

        if (nums[0] > 0) {
            return n;
        }

        return n + 1;    
    }
};