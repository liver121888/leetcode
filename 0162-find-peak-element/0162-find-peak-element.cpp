
// may have duplicates
// may have multiple peaks
// [1,2,3,1]

// we can O(n) check every spot and it's neighbor
// TLE

// peak
// first apperance of an element larger than both l and r

// if we have
// l = 1
// r = 1
// mid = 2
// mid+1 > n - 1 -> -inf
// nums[mid+1]
// see the trend
// upward trend
// right side have a peak is guaranteed
// downawrd trend
// left side have a peak

// [1]
// [1 2]

// [1,2,3,1]
// 2 3
// l = 2
// r = 1
// mid = 3
// l = 2
// r = 3
// l r = 3

// l r mid
// 比較 mid + 1 很方便

// [1,2,1,3,5,6,4]
// l 1
// mid 3
// r 4
// midNext 5
// 5 6 4
// 6 4
// l 5
// r = 6


class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while (l < r) {
            int mid = l + (r - l)/2;
            int midNext = mid + 1 < n ? nums[mid+1] : INT_MIN/2;
            if (nums[mid] < midNext) {
                l = mid + 1;
            } else {
                r = mid;
            }
        } 

        return r;
    }
};