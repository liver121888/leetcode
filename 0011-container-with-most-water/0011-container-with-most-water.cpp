class Solution {
public:
    int maxArea(vector<int>& height) {
        // brute force: O(n^2)
        // check each pair
        
        // two pointers: O(n)
        int maxVolume = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {           
            maxVolume = max(maxVolume, (right - left) * min(height[left], height[right]));
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        
        return maxVolume;
    }
};