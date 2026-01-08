// we have to do it in-place
// we can solve using two pointers
// [0,1,0,3,12]
// l r two pointers
// if nums[l] is 0
// we need to use r to find non zero and swap
// if nums[l] is not 0
// we move the r and l pointer tgt

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // int l = 0, r = 0;
        // while (r < nums.size()) {
        //     if (nums[l] != 0) {
        //         l++;
        //         r++;
        //     } else {
        //         while (r < nums.size() && nums[r] == 0) {
        //             r++;
        //         }
        //         if (r >= nums.size())
        //             break;
        //         // swap
        //         nums[l] = nums[r];
        //         nums[r] = 0;
        //         l++;
        //         r++;
        //     }
        // }
        

        int l = 0, r = 0;
        while (r < nums.size()) {
            if (nums[r] != 0) {
                // swap
                int tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
            }
            r++;
        }

        // [0,1,0,3,12], n = 5
        // l = 0, r = 1
        // [1, 0], l = 1 r = 2
        // [1, 0, 0, 3, 12]
        // [1, 3, 0, 0, 12]
        // [1, 3, 12, 0, 0]


        // [1, 3, 5, 6, 7]
       
        // int l = 0;
        // for (int r = 0; r < nums.size(); r++) {
        //     if (nums[r] != 0) {
        //         swap(nums[l], nums[r]);
        //         l++;
        //     }
        // }

        
    }
};