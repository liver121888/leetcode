
// initially we need to find which row is the target in
// and then binary search that row

// we need to search the first column, 
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 1 10 23
// first row
// find lower bound of target
// and then we search for that row

// complexity O(logm + log(n)) = O(log(m*n))
// space: O(1)

// 1 10 23
// target = 1
// // frist row
// find elemnt <= 3 

// 1 10 23
// target = 24

// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]

// target = 1
// target = 4
// r = 0


// target 61
// 1 10 23

// 直覺理解（很重要🔥）

// 你現在做的是：

// 先找 row，再找 column

// 但另一種寫法是：

// 把 matrix 當成一個「長度 m×n 的排序 array」

// 例如：

// [1,3,5,7,
//  10,11,16,20,
//  23,30,34,60]

// 👉 直接 binary search 一次：

// 範圍：0 ~ m*n-1
// mid → 映射回 matrix：
// row = mid / n
// col = mid % n

// 👉 這樣 complexity：

// O(log(m×n))


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        // binary search first column's element to find the row
        // I want to find the last one that is <＝ target
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // r will be our ans, beacuase r is finding the last one
        // l is finding the first one

        // search on that row
        int row = r;
        if (row < 0)
            return false;

        l = 0;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] < target) {
                l = mid + 1;
            } else if (matrix[row][mid] > target) {
                r = mid - 1;
            } else {
                return true;
            }
        }
        return false;

        
    }
};