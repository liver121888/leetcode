

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
        int r = 0;
        int ans = 0;
        for (; r < nums.size(); r++) {
            // why u don't need to shrink
            // The reason why we don't need to keep track of max length, 
            // is that even the actual valid interval is smaller than the 
            // current one. We have a previously valid answer. 
            // When there're no bigger intervals behind, we'll just submit 
            // this max length. Or when there're bigger result, we will update it.
            // In short, we only care about the max length.
            // while (nums[r] - nums[l] > 2 * k) {
            //     // shrink
            //     l++;
            // }
            // ans = max(ans, r - l + 1);
            if (nums[r] - nums[l] > 2 * k)       
                l++;
        }

        return r-l;        
    }
};