class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
                
        // only need subsequence
        sort(nums.begin(), nums.end());
        
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int ub = findUpperBound(nums, nums[i]+2*k);
            result = max(ub - i + 1, result);
        }
        
        return result;
        
    }
    
    
    int findUpperBound(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (arr[mid] <= target) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return result;
    }
};