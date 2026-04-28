
// non-increasing
// is valid
// i <= j and nums1[i] <= nums2[j]
// The distance of the pair is j - i​​​​
// Return the maximum distance of any valid pair (i, j). 
// If there are no valid pairs, return 0.

// Example 1:
// Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
// Output: 2
// Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
// The maximum distance is 2 with pair (2,4).
// i = 0
// j = 4
// 55, 5
// not valid
// how can we avoid local minimum and knows which pointer to move?

// bruteforce
// nums1 m, nums2 n
// O(m*n)
// O(1)


// Example 2:
// Input: nums1 = [2,2,2], nums2 = [10,10,1]
// Output: 1
// Explanation: The valid pairs are (0,0), (0,1), and (1,1).
// The maximum distance is 1 with pair (0,1).

// Example 3:
// Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
// Output: 2
// Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
// The maximum distance is 2 with pair (2,4).

// 1 <= nums1[i], nums2[j] <= 10^5

// to max distance
// j largest
// i smallest
// two pointers?
// the farthest j such that nums2[j] ≥ nums1[i] is at least as 
// far as the farthest j such that nums2[j] ≥ nums1[i-1]
// Time complexity: O(m+n)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0, p1 = 0, p2 = 0;
        
        while (p1 < nums1.size() && p2 < nums2.size()) {
            // If p1 is larger, we should move on to a smaller p1.
            if (nums1[p1] > nums2[p2]) {
                p1++;
            } else {
                // Otherwise, get their distance and move on to a smaller p2.
                ans = max(ans, p2 - p1);
                p2++;
            }
        }
        
        return ans;

        
    }
};