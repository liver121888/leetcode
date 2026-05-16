class Solution {
public:

    // unique elements

    int findMin(vector<int>& nums) {

        int n = nums.size();
        int l = 0, r = n - 1;

        // find minimum
        // find the first occurance
        // we return r

        while (l < r) {

            int mid = l + (r - l)/2;

            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return nums[r];
        
    }
};