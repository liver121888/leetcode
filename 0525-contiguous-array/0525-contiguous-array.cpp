// we need to find the longest subarray
// we can use two pointers
// l = 0, r = 0
// and when we expand, we see the element
// why we might not be able to use two pointers here?
// because shrinking the array might not always lead to 
// satisfying the condition
// we calculate the whole array to know the nums of zero and 
// ones
// zeroNum, oneNum
// we find subarray using two pointers, expand as much as it can
// when we reach equal number, max the dist
// if greater ones, we shrink

// O(n)
// O(1)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> aMap;
        aMap[0] = -1;              // base: count 0 at index -1

        int maxLen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] == 1 ? 1 : -1;
            auto it = aMap.find(count);
            if (it != aMap.end()) {
                maxLen = max(maxLen, i - it->second);
            } else {
                // only put it in when it does not exist
                aMap[count] = i;
            }

        }
        return maxLen;
    }
};