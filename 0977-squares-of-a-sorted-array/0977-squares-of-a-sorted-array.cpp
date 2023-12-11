class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int r = n - 1;
        int l = 0;
        for (int i = n - 1; i >=0; i--) {
            if (abs(nums[l]) > abs(nums[r])) {
                ans[i] = nums[l]*nums[l];
                l += 1; 
            } else {
                ans[i] = nums[r]*nums[r]; 
                r -= 1;                
            }
        }        
        return ans;        
    }
};