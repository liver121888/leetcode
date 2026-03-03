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

// find left boundary
// O(log(N−k)+k) time
// O(1) space
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Initialize binary search bounds
        int left = 0;
        int right = arr.size() - k;
        
        // Binary search against the criteria described
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // Create output in correct format
        vector<int> result;
        for (int i = left; i < left + k; i++) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};

// class Solution {
// public:
//     // 從兩側開始
//     //     為什麼這版不會出錯？
//     // 永遠只在 l>=0 時讀 arr[l]，只在 r<n 時讀 arr[r]
//     // 區間語意固定：選到的元素永遠是 (l, r) 開區間
//     // tie-break 明確：<= 代表距離一樣選左邊（較小）
//     // 時間：O(log n + k)，因為我們先search然後linear擴張，空間：O(1)（不算輸出）
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         int n = (int)arr.size();
//         int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//         int l = r - 1;

//         while (k--) {
//             if (l < 0) {
//                 r++;
//             } else if (r >= n) {
//                 l--;
//             } else {
//                 // tie -> pick left (smaller value)
//                 if (x - arr[l] <= arr[r] - x) l--;
//                 else r++;
//             }
//         }

//         // selected range is (l, r)
//         return vector<int>(arr.begin() + (l + 1), arr.begin() + r);
//     }
// };


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
