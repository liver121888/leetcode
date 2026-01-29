// this is a subarray problem
// we can solve using two pointers
// we can calculate prefix sum
// [1, 1, 1]
// [1, 2, 3]
// so we can come up with each subarray sum
// [1,2,3], k = 3
// [1, 3, 6]
// we traverse throught once, to see if they equal to k
// then 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // vector<int> prefixSum;
        // prefixSum.push_back(0);
        // int currSum = 0;
        // for (auto num : nums) {
        //     currSum += num;
        //     prefixSum.push_back(currSum);
        // }
        // int count = 0;
        // for (int start = 0; start < nums.size(); start++) {
        //     for (int end = start + 1; end <= nums.size(); end++) {
        //         if (prefixSum[end] - prefixSum[start] == k)
        //             count++;
        //     }
        // }

        // return count;

        // time: O(n^2);
        // space: O(n);


        int count = 0, sum = 0;
        unordered_map<int, int> lookUp;
        lookUp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //  sums[i]−sums[j]=k
            // so we find sums[i] - k = sums[j] in the lookUp
            if (lookUp.find(sum - k) != lookUp.end()) {
                count += lookUp[sum-k];
            }
            lookUp[sum]++;
        }
        return count;




        // -1000 <= nums[i] <= 1000
        // then we cannot use two pointers cuz shrink not necessnary decrease

        // int l = 0, curr = 0, cnt = 0;
        // for (int r = 0; r < nums.size(); r++) {
        //     curr += nums[r];
        //     while (curr > k && l <= r) {
        //         // shrink
        //         curr -= nums[l];
        //         l++;
        //     }

        //     if (curr == k)
        //         cnt += 1;

        //     // expand
        // }
        // return cnt;

        // [1, 1, 1], k = 2
        // l = 0, curr = 0, cnt = 0, r = 0;
        // curr = 1
        // l = 0, curr = 1, cnt = 0, r = 1;
        // curr = 2, cnt = 1
        // l = 0, curr = 1, cnt = 0, r = 2;
        // curr = 2, cnt = 1
        // cnt = 2, return 2
        // nums = [1,2,3], k = 3
        // nums = [100], k = 0

    }
};