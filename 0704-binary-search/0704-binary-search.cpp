class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [-1,0,3,5,9,12]
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            int v = nums[mid];
            if (v == target) {
                return mid;
            } else if (v < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;

    }
};