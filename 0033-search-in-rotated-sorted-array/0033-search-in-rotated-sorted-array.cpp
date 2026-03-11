
// O(log n) 
// [0,1,2,4,5,6,7]
// [4,5,6,7,0,1,2]

// nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// Input: nums = [1], target = 0
// Output: -1

class Solution {
public:


    // values are distinct
    // nums is an ascending array that is possibly rotated.
    // binary search
    // [4,5,6,7,0,1,2]
    // l = 0, r = 6, mid = 3
    // 7 > 4 , 7 > 2 target = 0
    // left half is ordered
    // check if target is in that
    // if not, go to the other half
    // l = mid + 1
    // l = 4 r = 6
    // mid = 5 == target -> return
    // l = 5 r = 6
    // mid = 5

    // binary search 每次都要維持這個 invariant：
    // 如果 target 存在，它一定還在 [l, r] 裡面。
    // 1. 哪半有序？
    // 是左半還右半？
    // 2. target 有沒有落在那個有序半邊的值域內？
    // 不是看位置，是看值。
    // 3. 我這次丟掉的那一半，真的不可能含 target 嗎？
    // 如果你答不出來，表示縮錯了。
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r)/2;

            if (nums[mid] == target)
                return mid;

            // left part ordered
            if (nums[l] <= nums[mid]) {
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                // right part ordered
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};