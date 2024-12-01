class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            
            // `low` indicates the number of possible pairs with sum < lower.
            int lowIdx =
                lower_bound(nums, i + 1, nums.size() - 1, lower - nums[i]);

            // `high` indicates the number of possible pairs with sum <= upper.
            int upIdx =
                lower_bound(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);
            
            cnt += upIdx -lowIdx;            
        }
        
        // cout << binarySearch(nums, 2) << endl;
        
        return cnt;
    }
    
    long long lower_bound(vector<int>& nums, int low, int high, int element) {
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] >= element) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
    
    
};