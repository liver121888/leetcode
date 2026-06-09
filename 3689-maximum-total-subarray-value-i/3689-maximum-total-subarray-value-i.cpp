// Input: nums = [1,3,2], k = 2
// subarray, take max and min, sum there diff
// can we greedily take the whole max and the whole min
// then times it k times?

// ok can k be negative numbers?
// no, k is positive
// nums can have negaitve number
// if I choose smth that is not the largest and min
// we cannot produce the largest diff
// so we can solve using greedy method
// assume nums is non empty
// assume the sum can fit in long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());

        long long diff = (long long)maxElement - minElement;
        return diff * k;
    }
};