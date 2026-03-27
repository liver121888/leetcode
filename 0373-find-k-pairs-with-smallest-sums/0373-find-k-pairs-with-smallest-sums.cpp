
// non-decreasing order 
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

// Example 1:
// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

// Example 2:
// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// nums1 and num2 can be not the same size
// negaitve numbeers
// can we reuse the elemetns
// ex1 shows that we can reuse elements
// but we have to the pair must have one from nums1 and one from nums2

// nums1 = [2,7,11], nums2 = [2,4,6, 7, 8]

// 2,2 2,4 .... 7,2, 7,4
// nums1 size is n, nums2 size m -> (n*m)


// 2 -> 7

// 2 -> 4 -> 6

// 2,2 2,4 2,6 or 7,6
// maxHeap of size k
// traverse throught all the values
// n*m*log(k)


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // max heap
        // priority_queue<pair<int, pair<int,int>>> pq;

        // for (const auto& num1 : nums1) {
        //     for (const auto& num2 : nums2) {
        //         pq.push({num1 + num2, {num1, num2}});

        //         if (pq.size() > k)
        //             pq.pop();
        //     }

        // }

        // vector<vector<int>> ans;
        // while (!pq.empty()) {
        //     auto data = pq.top();
        //     ans.push_back({data.second.first, data.second.second});
        // }
        // return ans;


        // nums1 = [1,7,11], nums2 = [2,4,6,10,12]

        // nums1 = [2,4,6,10,12], nums2 = [1,7,11]


        // nums1[i] + nums2[0]
        // starts with the one that is longer 
        // let's say nums1 is always longer
        // [3, 5, 7, 11, 13]
        // decide when do we shift to next index in the nums1

        // other than that we just keep putting the pairs until we get k pairs
        // 2, 1

        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        set<pair<int,int>> visited;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0,0});

        while (k-- && !minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};