
// initially we need to find which row is the target in
// and then binary search that row

// we need to search the first column, 
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 1 10 23
// first row
// find lower bound of target
// and then we search for that row

// complexity O(logm + log(n))
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


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int m = matrix.size();
        int n = matrix[0].size();

        // binary search first column's element to find the row
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // r will be our ans

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