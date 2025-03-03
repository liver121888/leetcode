class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        queue<int> smaller;
        queue<int> larger;
        int pCnt = 0;

        for (auto num : nums) {
            if (num > pivot)
                larger.push(num);
            else if (num < pivot)
                smaller.push(num);
            else
                pCnt++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!smaller.empty()) {
                nums[i] = smaller.front();
                smaller.pop();
            } else if (pCnt != 0) {
                nums[i] = pivot;
                pCnt--;
            } else {
                if (!larger.empty()) {
                    nums[i] = larger.front();
                    larger.pop();
                }
            }
        }

        return nums;
    }
};