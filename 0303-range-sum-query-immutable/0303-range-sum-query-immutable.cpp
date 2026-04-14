
// simply build a prefix sum array
class NumArray {
public:

    vector<int> prefixSum;

    NumArray(vector<int>& nums) {

        int n = nums.size();
        prefixSum = vector<int>(n + 1);
        for (int i = 0; i < n; i++)
            prefixSum[i+1] = nums[i] + prefixSum[i];
        
    }
    
    int sumRange(int left, int right) {

        return prefixSum[right+1] - prefixSum[left];
        
    }
};


// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// [0, -2, -2, 1, -4, -2, -3]
// [0 2] = 1
// [2 5] = -1, -3-(-2) = -1
// [0 5] = dp[6] - dp[0] = -3


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */