class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int val; int r; int l; int ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            r = nums.size() - 1;
            l = i + 1;
            while (l < r) {
                val = nums[i] + nums[l] + nums[r];  
                if (abs(target - val) < abs(target - ans))
                    ans = val;
                
                if (val == target) {
                    return target;
                } else if (val > target) {
                    r--;
                    while (nums[r] == nums[r + 1] && l < r) {
                        r--;
                    }
                } else {
                    l++;
                    while (nums[l] == nums[l - 1] && l < r ) {
                        l++;
                    }
                }
            }                

        }
        return ans;        
    }
};