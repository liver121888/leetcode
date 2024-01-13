class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0; int right = height.size() - 1;
        int maxLeft = height[left]; int maxRight = height[right]; 
        while (left < right) {
            if (maxLeft < maxRight) {
                left++;
                maxLeft = max(maxLeft, height[left]);
                ans += maxLeft - height[left];
            }
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                ans += maxRight - height[right];
            }
        }
        return ans;
    }
};