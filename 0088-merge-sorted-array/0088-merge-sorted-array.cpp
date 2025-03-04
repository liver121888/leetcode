class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // [1 2 3 0 0 0]
        // [2 5 6]
        // 6 vs 3
        // put 6
        // j--
        // keep checking until we deplete
        // edge case
        // [1 5 5 0 0 0]
        // [1 2 3]
        // since there are m + n spots, I would not overwrite
         
        int i = m - 1; int j = n - 1;
        int ins = m + n - 1;

        while (j >= 0 && i >= 0 && ins >= 0) {
            cout << " " << i << " " << j << " " << ins << endl;
            int tmp;
            if (nums1[i] > nums2[j]) {
                tmp = nums1[i];
                i--;
            } else {
                tmp = nums2[j];
                j--;
            }
            nums1[ins] = tmp;
            ins--;
        }

        while (j >= 0) {
            // cout << j << endl;
            nums1[ins] = nums2[j];
            ins--;
            j--;
        }

        while (i >= 0) {
            nums1[ins] = nums1[i];
            ins--;
            i--;
        }

        // [1 2 3 0 0 0]
        // [2 5 6]
        // ins = 5, i = 2, j = 2
        // [1 2 3 3 5 6]
        // [2 5 6]
        // ins = 2, i = 1, j = 0
        // 2 vs 2
        // [1 2 2 3 5 6]
        // ins = 1, i = 1, j = -1

        // [0] [1] m = 0, n = 1
        // ins = 0, i = -1, j = 0

    }
};