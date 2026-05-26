
// All the integers in nums appear only once except 
// for precisely one integer which appears two or more times.
 
// Follow up:
// How can we prove that at least one duplicate 
// number must exist in nums?
// Can you solve the problem in linear 
// runtime complexity?

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;

    }
};