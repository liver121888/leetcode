

// The overall run time complexity should be O(log (m+n))
// 1, 2
// 3, 4

// size 6
// 1, 2, 5, 6, 8, 11 -> median 11/2
// size 5
// 3, 4, 5, 6, 7 -> media = 5

// size 11 -> element 6 index 5
// 1, 2, 3, 4, 5, 5, 6, 6, 7, 8, 11 -> median = 5


// m + n
// then we know the median we are looking for
// either (m + n)/2 if odd number
// average of (m+n)/2 and (m+n)/2-1 if even


// 我能不能直接把兩個 sorted arrays 切成左半、右半，
// 讓左半剛好包含前一半元素？
// 先想中位數本質
// 假設總長度是 total = m + n
// 我們希望切完之後：
// 左邊總共有 half = (total + 1) / 2 個元素
// 右邊是剩下的元素
// 為什麼用 (total + 1) / 2？
// 因為這樣：
// odd 時，左邊會多一個，中位數就是左邊最大值
// even 時，左邊右邊一樣多，中位數是
// 左邊最大值 和 右邊最小值 的平均
// 核心轉換
// 假設：
// 在 nums1 切在位置 i
// 在 nums2 切在位置 j
// 那就要滿足：
// i + j = half
// 也就是：
// j = half - i
// 所以你其實只要決定 i，j 就跟著確定了。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        // keep m is the smaller one
        // we only binary search i on the smaller one
        int half = (m + n + 1) / 2;
        // why r = m? because we might split at the end
        int l = 0, r = m;

        // Aleft = A[...i] Aright = A[i+1...]
        // Bleft = B[...j] Bright = B[j+1...]
        // Aleft <= Bright
        // Bleft <= Aright

        while (l <= r) {
            int i = l + (r-l)/2;
            int j = half - i;

            int Aleft  = (i == 0 ? INT_MIN : nums1[i - 1]);
            int Aright = (i == m ? INT_MAX : nums1[i]);
            int Bleft  = (j == 0 ? INT_MIN : nums2[j - 1]);
            int Bright = (j == n ? INT_MAX : nums2[j]);

            if (Aleft <= Bright && Bleft <= Aright) {
                // even
                if ((m + n)%2 == 0) {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                } else {
                    return max(Aleft, Bleft);
                }

            } else if (Aleft > Bright) {
                r = i - 1;
            } else {
                l = i + 1;
            }

            // if (Aleft <= Bright && Bleft <= Aright) {
            //     ...
            // } else if (Aleft > Bright) {
            //     ...
            // } else {
            //     ...
            // }
        }
        return -1;


        
    }
};