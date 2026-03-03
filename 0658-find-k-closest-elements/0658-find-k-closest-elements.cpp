// if the distance is the same, we pick the one that is smaller
// the array is sorted
// we are given k and x
// there will be duplicate

// we can binary search, then start to find the numbers and return k numbers
// The result should also be sorted in ascending order
// arr = [1,2,3,4,5], k = 4, x = 3
// idx = 2
// come up with l r pointer both starts at idx
// (r - l + 1) == k
// l keep spanding
// and we compare r and l
// every time we expand to the smallest possible numbers
// r < n,  l >= 0

// in the end we subarray l to r and return

class Solution {
public:
    // 從兩側開始
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = (int)arr.size();
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;

        while (k--) {
            if (l < 0) {
                r++;
            } else if (r >= n) {
                l--;
            } else {
                // tie -> pick left (smaller value)
                if (x - arr[l] <= arr[r] - x) l--;
                else r++;
            }
        }

        // selected range is (l, r)
        return vector<int>(arr.begin() + (l + 1), arr.begin() + r);
    }
};


// class Solution {
// public:

//     // 為什麽這版容易出錯?
//     // upper_bound可能會找到arr.end()代表x比所有元素都大
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
//         int n = arr.size();
//         auto it = upper_bound(arr.begin(), arr.end(), x);
//         int idx = it - arr.begin();

//         int l = idx, r = idx;
//         while (r - l + 1 < k && r < n && l >= 0) {

//             int rDiff = abs(arr[r] - x);
//             int lDiff = abs(arr[l] - x);

//             if (rDiff < lDiff) {
//                 // take the number on r
//                 r++;
//             } else {
//                 // take the number on l
//                 l--;
//             }
//         }

//         // take l side
        
//         if (r >= n) {
//             int currLen = (r - 1) - l + 1;
//             l -= k - currLen;
//         }

//         if (l < 0) {
//             int currLen = r - (l + 1) + 1;
//             r += k - currLen;
//         }


//         vector<int> ans(k);
//         // subvector from l ro r inclusive
//         for (int i = 0; i < k; i++) {
//             ans[i] = arr[l+i];
//         }
//         return ans;
//     }
// };
