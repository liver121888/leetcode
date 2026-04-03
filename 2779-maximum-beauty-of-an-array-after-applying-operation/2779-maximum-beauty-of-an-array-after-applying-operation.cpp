

// maximumBeauty
// the longest subsequce that can form
// of the same element
// for each element we can only operate once
// either up or down
// and we want to maximize the frequence of a cetain element

// one way we can do is
// traverse the array, get the range 
// max min -> mid
// see every element and see how many elements is up or down
// what's bounding the beauty?
// the min element and max element


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        // Hint 1
        // Sort the array.
        // Hint 2
        // The problem becomes the following: find maximum subarray A[i … j] such that A[j] - A[i] ≤ 2 * k.

        sort(nums.begin(), nums.end());

        int l = 0;
        int ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > 2 * k) {
                // shrink
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;        
    }
};