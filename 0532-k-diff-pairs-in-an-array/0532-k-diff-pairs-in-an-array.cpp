// one way we can brute force this is
// two for loops
// check each pair
// see the diff
// O(n^2), O(1)
// we also need unique pairs so we have a set to track that
// the sequence does not matter here
// we can sort the array
// traverse the array and see the unique pairs
// we can use sliding window
// l and r
// if (nums[r] - nums[l] == k)
// cnt++ and shrink
// if <
// if >
// we also use a set to keep uniqueness
// time: O(nlogn)
// space: O(n)

// some edge case: k = 0
// empty nums

// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

// Input: nums = [1,3,1,5,4], k = 0
// Output: 1
// Explanation: There is one 0-diff pair in the array, (1, 1).

// [1,3,1,5,4]
// [1 1 3 4 5]
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        // use unordered_map to track the freq
        unordered_map<int, int> freq;
        for (int num : nums)
            freq[num]++;

        int ans = 0;
        for (const auto [num, cnt] : freq) {
            if (k == 0) {
                if (cnt >= 2)
                    ans++;
            } else {
                // why only find + k?
                // because we want unique pairs
                // (1, 3), (3, 1) should only be cnt once
                // using unordered_map instead of map
                // to check existance of num + k
                if (freq.find(num + k) != freq.end()) {
                    ans++;
                }
            }

        }
        return ans;

        // int n = nums.size();
        // if (n <= 1)
        //     return 0;

        // sort(nums.begin(), nums.end());

        // // at least size 2
        // int l = 0, r = 1;
        // set<pair<int,int>> aSet; 
        // while (r < nums.size()) {
        //     int diff = nums[r] - nums[l];
        //     // cout << l << " " << r << endl;
        //     if (l == r)
        //         r++;
        //     if (diff == k) {
        //         aSet.insert({nums[l], nums[r]});
        //         r++;
        //     } else if (diff > k) {
        //         l++;
        //     } else {
        //         r++;
        //     }
        // }
        // return aSet.size();   


        // we track the freq
        // and see the diff is 1
        // num, freq
        // map<int, int> freqMap;
        // for (int num : nums) {
        //     freqMap[num]++;
        // }

        // if (k == 0) {


        // } else {

        //     auto it = freqMap.begin();
        //     for (const auto& [num, freq] : freqMap) {
        //         if (abs(it.first - num) == k) {
        //             ans++;
        //         }


        //     }

        // }
        // return ans;
    }
};