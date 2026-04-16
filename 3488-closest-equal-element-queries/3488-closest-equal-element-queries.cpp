
// The minimum distance between the element at index queries[i] and any 
// other index j in the circular array, where nums[j] == nums[queries[i]]. 
// If no such index exists, the answer for that query should be -1.

// we can use a hash map to save the indices of elements
// when query, we get the element and see the minimum distance index
// nums = [1,3,1,4,1,3,2], queries = [0,3,5]
// 1: 0,2,4
// 2: 6
// 3: 1,5
// 4: 3

// query 0 -> 1: [0 2 4], calculate the circular distance and take the smallest
// abs(2 - 0) and n = 7, 7 - abs(2) = 5
// ...

// edge case: single element -> return -1
// empty [] -> empty vector
// empty nums: return empty vector also

// 看到你的程式碼在處理環狀陣列（Circular Array）距離時遇到了 TLE (Time Limit Exceeded)，
// 這通常是因為當某個數字出現頻率很高時，巢狀迴圈（對每個查詢都遍歷該數字的所有索引）
// 會導致最差情況下的時間複雜度接近 $O(Q \times N)$。我們可以透過預處理或更有效率的二分搜尋來優化。
// 1. 問題分析與思路優化目前的瓶頸在於：如果 nums 裡全是同一個數字，
// 每次查詢你都要重新計算它與所有其他索引的距離。
// 優化策略：二分搜尋 (Binary Search)由於我們已經將索引儲存在 e2i[element] 中，
// 且這些索引是由小到大排序的，我們不需要遍歷所有的 idx。對於一個查詢索引 
// $q$：最接近 $q$ 的索引只會出現在 e2i[element] 中 $q$ 的 左側第一個 或 右側第一個。
// 考慮到環狀特性，我們還需要檢查該數字在陣列中的 首位 與 末位 索引。
// 這樣可以將每次查詢的時間複雜度從 $O(N)$ 降低到 $O(\log N)$。

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();
        int qSize = queries.size();
        vector<int> ans;

        if (n == 0 || qSize == 0)
            return ans;

        unordered_map<int,vector<int>> e2i;

        // save element to indices
        // this is already sorted!
        // very important property
        for (int i = 0; i < n; i++) {
            e2i[nums[i]].push_back(i);
        }

        ans.resize(qSize);
        for (int j = 0; j < qSize; ++j) {

            int q = queries[j];
            int element = nums[q];
            const vector<int>& indices = e2i[element];
            int idxSize = indices.size();

            // 如果該數字只出現一次，無法找到「其他」索引
            if (idxSize <= 1) {
                ans[j] = -1;
                continue;
            }

            // largest possible
            int minDist = n;
            auto it = lower_bound(indices.begin(), indices.end(), q);
            int pos = it - indices.begin();

            // 1: 0,2,4
            // pos = 0

            if (pos - 1 >= 0) {
                // then there is a left that we should check
                int d = q - indices[pos - 1];
                // minDist = min(min(minDist, d), n - d); 
                minDist = min(minDist, d); 
            } else {
                // then we should check the end because it's circular
                int d = indices.back() - q;
                // minDist = min(min(minDist, d), n-d); 
                minDist = min(minDist, n-d); 
            }

            if (pos + 1 < idxSize) {
                // then there is a right that we should check
                int d = indices[pos + 1] - q;
                // minDist = min(min(minDist, d), n-d);
                minDist = min(minDist, d); 

            } else {
                // then we should check the fronnt because it's circular
                int d = q - indices.front();
                // minDist = min(min(minDist, d), n-d); 
                minDist = min(minDist, n-d); 

            }

            ans[j] = minDist;

        }

        return ans;
    }
};

