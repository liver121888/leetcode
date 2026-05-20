
// non-decreasing order,
class Solution {
public:


    // Example 1:
    // Input: nums = [5,7,7,8,8,10], target = 8
    // Output: [3,4]
    // l = 0;
    // r = 6; 
    // mid = 3;

    // r = 3, 8
    // l = 3, 8
    // mid = 1

    // l = 0;
    // r = 6; 
    // mid = 3; 8
    // l = 4
    // r = 5
    // mid = 5

    // 2, 2
    // n = 2
    // l = 0
    // r = 2
    // mid = 1

    // r = 0
    // l = 0


    vector<int> searchRange(vector<int>& nums, int target) {

        // the start and the end of the target value
        // if not found, return -1,-1

        // binary search 
        // element >= target
        // element > target
        int n = nums.size();
        if (n == 0)
            return {-1, -1};
        if (n == 1)
            return nums[0] == target ? vector<int>({0, 0}) : vector<int>({-1, -1});
        
        int l = 0, r = n;

        // find first element >= target
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int firstAns = -1;
        if (l >= 0 && l < n)
            firstAns = nums[l] == target ? l : -1;


        // l will be the ans
        // int firstAns =  

        l = 0;
        r = n;

        // find first element > target
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        // we need inclusive range
        int secondAns = -1;
        if (l - 1 >= 0 && l - 1  < n)
            secondAns = nums[l - 1] == target ? l - 1 : -1;

        return {firstAns, secondAns};

    }
};