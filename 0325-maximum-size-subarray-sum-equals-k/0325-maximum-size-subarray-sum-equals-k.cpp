class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        // because there is negative number, we cannot simply use two pointers
        // because shrinking is not necessnary will help us getting closer to k

        // prefix sum -> can get any subarray sum in O(1)
        // the max possible array -> entire array

        // brute-force check (n^2)

        // n+1
        // vector<long long> prefixSum;
        long long runningSum = 0;

        long long longestSubarray = 0;
        unordered_map<long long, long long> indices;

        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            // prefixSum.push_back(runningSum);
            if (runningSum == k) {
                longestSubarray = i + 1;
            }

            if (indices.find((long long)runningSum - k) != indices.end())
                longestSubarray = max(longestSubarray, (long long)i - indices[runningSum - k]);

            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (indices.find(runningSum) == indices.end()) {
                indices[runningSum] = i;
            }
        }

        // for (int i = 0; i < prefixSum.size(); i++) {
        //     k - prefixSum[i]
        //     // for (int j = i + 1; j < prefixSum.size(); j++) {
        //     //     int currSum = prefixSum[j] - prefixSum[i];
        //     //     if (currSum == k)
        //     //         ans = max(j-i, ans);
        //     // }
        // }
        return longestSubarray;
    }
};