
// Note that it is the kth largest element in the sorted order, 
// not the kth distinct element.

// Can you solve it without sorting?

// we can build a max heap and pop k times
// or we can build a min heap of size K
// everytime we push and if the size > k, we pop

// Example 1:
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// minHeap of size k
// 2, 3
// 2, 3
// 3, 5
// 5, 6

// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// 1 2 3 3
// 2 2 3 3
// 2 3 3 4
// 2 3 4 5
// 3 4 5 5 
// 4 5 5 6

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (const int& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
        
    }
};