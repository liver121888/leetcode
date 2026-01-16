// we can create a hashmap and count through the array
// time: O(n)
// space: O(n)
// The majority element is the element that appears more than ⌊n / 2⌋ times
// we can do like a voting thing
// the majority element will wins
// everytime 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for (int& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};