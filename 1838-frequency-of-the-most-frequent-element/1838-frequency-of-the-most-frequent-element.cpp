class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {      
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int left = 0;
        int maxLength = 0;
        long long curSum = 0;
        long long target = 0;
        for (int right = 0; right < n; right++) {
            target = nums[right];
            curSum += target;
            while((right - left + 1) * target - curSum > k) {
                curSum -= nums[left];
                left++;  
            }
            maxLength = max(right - left + 1, maxLength);
        }
        return maxLength;
    }
};