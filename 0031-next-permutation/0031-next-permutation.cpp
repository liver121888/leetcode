

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] 
// because [3,2,1] does not have a lexicographical larger rearrangement.
// The replacement must be in place and use only constant extra memory.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,3,2]

// Example 2:
// Input: nums = [3,2,1]
// Output: [1,2,3]

// Example 3:
// Input: nums = [1,1,5]
// Output: [1,5,1]

// Use two pointers
// Find the largest index i such that nums[i] < nums[i+1]:
// This step identifies the longest suffix that is in non-increasing order. 
// If no such index exists, the array is in the highest possible permutation, 
// and we can directly reverse it to return to the smallest permutation.

// Find the largest index j greater than i such that nums[i] < nums[j]:
// This step finds the element that will replace nums[i] to create the next larger 
// permutation. Specifically, j is the smallest number greater than nums[i] that 
// can be swapped with it to get the next permutation.

// Swap nums[i] and nums[j]:
// After swapping, the number at index i will be in a position where it is now larger 
// than its previous value, but we still have a non-increasing sequence to the right.

// Reverse the sequence from i + 1 to the end of the array:
// After swapping, the numbers to the right of index i will be in descending order, 
// so we need to reverse them to get the smallest lexicographical order.


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the largest index i such that nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such an index i exists, find the largest index j > i such that nums[i] < nums[j]
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            
            // Step 3: Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the subarray nums[i + 1...n-1]
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};

