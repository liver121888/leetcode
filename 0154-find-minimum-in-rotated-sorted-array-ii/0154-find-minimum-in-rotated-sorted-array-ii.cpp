// return the minimum element of this array.

// [2,2,2,0,1]
// n = 5
// l = 0 -> 2
// r = 4 -> 1
// mid = 2 -> 2

// mid ~ l is sorted




class Solution {
public:
    // that may contain duplicates
    int findMin(vector<int>& nums) {

        int n = nums.size();

        // has rotation
        // so the array becomes 2 segments
        // first increase seq
        // second increase seq
        int l = 0;
        int r = n - 1;

        // then here, we are finding the first index makes nums[i] < nums[0]
        // [2,2,2,0,1]

        while (l < r) {

            int mid = (l + r)/2;

            if (nums[mid] < nums[0]) {
                r = mid;
            } else if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r--;
            }

        }
        return nums[l];

    }
};

