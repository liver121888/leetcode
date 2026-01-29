class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // create a unordered_set to store all the things we saw
        // if the num-1 is not in the unordered_set, we know we found the head of a sequence
        // and we just keep looking until the traverse is the longest
        unordered_set<int> aSet(nums.begin(), nums.end());

        // at least itself is a consecutive seq
        // nums.length could be 0
        int ans = 0;
        for (auto& num : aSet) {
            if (aSet.find(num-1) == aSet.end()) {
                // traverse
                int curr = num;
                int currLen = 1;
                while (aSet.find(curr + 1) != aSet.end()) {
                    currLen++;
                    curr++;
                }
                ans = max(ans, currLen);
            }
        }
        return ans;

        // [100,4,200,1,3,2]
        
    }
};