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

// use index as unordered_set!
class Solution {
public:

    // int firstMissingPositive(vector<int>& nums) {

    //     bool containsOne = false;
    //     int n = nums.size();

    //     // clever, we need to check of n also
    //     for (auto& num : nums) {
    //         if (num == 1)
    //             containsOne = true;
    //         else if (num <= 0 || num > n)
    //             num = 1;
    //     }

    //     if (!containsOne)
    //         return 1;

    //     for (int i = 0; i < n; i++) {
    //         int value = abs(nums[i]);
    //         // use 0 as the n counter
    //         if (value == n) {
    //             nums[0] = -abs(nums[0]);
    //         } else {
    //             nums[value] = -abs(nums[value]);
    //         }
    //     }

    //     // scan the values that appeared
    //     for (int i = 1; i < n; i++) {
    //         if (nums[i] > 0)
    //             return i;
    //     }

    //     if (nums[0] > 0) {
    //         return n;
    //     }

    //     return n + 1;    
    // }

    // Cycle Sort
    // The numbers we need to check for are in the range 1 to n, 
    // so we can utilize cycle sort. Cycle sort is a sorting algorithm 
    // that can sort a given sequence in a range from a to n by putting each 
    // element at the index that corresponds to its value.

    // nums is a zero-indexed array, so an element with the value x 
    // will be located at index x - 1

    // This approach modifies the input. 
    // It changes the order of nums, but not the values of nums. 
    // In-place algorithms overwrite the input to save space, 
    // but sometimes this can cause problems. Always check with your 
    // interviewer before modifying the input.

    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;

    }


};