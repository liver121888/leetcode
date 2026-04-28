class Solution {
public:

    int search(const vector<int>& nums, int target, int start, int dir) {

        int n = nums.size();
        int boundary = n;
        if (dir == -1)
            boundary = -1;

        for (int i = start; i != boundary; i += dir) {
            if (nums[i] == target)
                return abs(i - start);
        }
        return n;
    }


    int getMinDistance(vector<int>& nums, int target, int start) {

        // we can start from the start and expand to see target
        // it is guaranteed that target exist

        int result1 = search(nums, target, start, -1);
        int result2 = search(nums, target, start, 1);
        return min(result1, result2);
        
    }
};