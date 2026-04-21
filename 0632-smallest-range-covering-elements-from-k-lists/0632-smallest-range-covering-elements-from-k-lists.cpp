
// smallest range that contains at least one element from each list
//  k lists of sorted integers in non-decreasing order.

// The important point here is that, at any time, our range is defined 
// by the smallest number chosen and the largest number chosen.
// So, to find the smallest range, we need to minimize the difference 
// between the largest and smallest numbers chosen at each step.

// time: O(n⋅k)
// space: O(k)
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
        
//         int k = nums.size();
//         // Stores the current index of each list
//         vector<int> indices(k, 0);
//         // To track the smallest range
//         vector<int> range = {0, INT_MAX};

//         while (true) {
//             int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

//             // Find the current minimum and maximum values across the lists
//             for (int i = 0; i < k; i++) {
//                 int currentElement = nums[i][indices[i]];

//                 // Update the current minimum
//                 if (currentElement < curMin) {
//                     curMin = currentElement;
//                     minListIndex = i;
//                 }

//                 // Update the current maximum
//                 if (currentElement > curMax) {
//                     curMax = currentElement;
//                 }
//             }

//             // Update the range if a smaller one is found
//             if (curMax - curMin < range[1] - range[0]) {
//                 range[0] = curMin;
//                 range[1] = curMax;
//             }

//             // Move to the next element in the list that had the minimum value
//             if (++indices[minListIndex] == nums[minListIndex].size()) break;
//         }

//         return range;
//     }
// };

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue to store (value, list index, element index)
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>> pq;
                    
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        // Insert the first element from each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        // Continue until we can't proceed further
        while (pq.size() == nums.size()) {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;

            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};