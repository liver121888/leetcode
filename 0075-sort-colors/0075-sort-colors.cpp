class Solution {
public:
    void sortColors(vector<int>& nums) {

        // // For all idx < p0 : nums[idx < p0] = 0
        // // curr is an index of elements under consideration
        // int p0 = 0, curr = 0;

        // // For all idx > p2 : nums[idx > p2] = 2
        // int p2 = nums.size() - 1;

        // while (curr <= p2) {
        //     if (nums[curr] == 0) {
        //         swap(nums[curr++], nums[p0++]);
        //     } else if (nums[curr] == 2) {
        //         swap(nums[curr], nums[p2--]);
        //     } else 
        //         curr++;
        // }

        // 3 ptrs
        // ptr0, ptr2 are the putting place
        // ptr1 is the picking place;

        int ptr0 = 0, ptr1 = 0;
        int ptr2 = nums.size() - 1;

        while (ptr1 <= ptr2) {
            if (nums[ptr1] == 0) {
                swap(nums[ptr1], nums[ptr0]);
                ptr0++;
                ptr1++;
            } else if (nums[ptr1] == 2) {
                swap(nums[ptr1], nums[ptr2]);
                ptr2--;
            } else {
                ptr1++;
            }
        }






        // vector<int> cnts(3);
        // for (auto num : nums)
        //     cnts[num]++;

        // int idx = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     while (cnts[idx] == 0)
        //         idx++;
        //     nums[i] = idx;
        //     cnts[idx]--;
        // }
    }
};