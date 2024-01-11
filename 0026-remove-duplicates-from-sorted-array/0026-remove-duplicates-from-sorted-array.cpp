class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertPos = 0;
        int takePos = 0;
        int k = 1;
        
        while (takePos < nums.size()) {
            if (nums[insertPos] == nums[takePos]) {
                takePos++;
            } else {                
                k++;
                nums[insertPos + 1] = nums[takePos];
                insertPos++;
                takePos++;
            }
        }
        return k;   
    }
};