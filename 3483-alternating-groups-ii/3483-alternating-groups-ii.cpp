class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        // subarray problem
        // need to find every size k subarray, also consider circle
        // need to check if still alternating
        // r can go beyond colors.size(), if it goes beyond minus out the size of colors
        // I only need to cycle r when indexing, r and l can stay the same

        int n = colors.size();
        int l = 0; int r = 0; int prev = -1;
        int result = 0;
        // at most can go beyond k - 1
        while (r < n + k - 1) {

            int windowSize = r - l + 1;
            // contracts
            if (windowSize > k) {
                l++;
            }
            // recal windowSize
            windowSize = r - l + 1;

            // cout << "l: " << l << " r: " << r << " result: " << result << endl;
            // cout << prev << " " << colors[r] << endl;

            // only need to index colors differently, r can stay the same
            int idx_r = r >= n ? r - n : r;

            // still alternating
            if (prev != colors[idx_r]) {
                if (windowSize == k)
                    result += 1;
            } else {
                // skip to r cuz not alternating
                l = r;
            }

            prev = colors[idx_r];
            // expand
            r++;
        }
        
        return result;        
    }
    // [0,1,0,1,0], k = 3
    // l = 0, r = 0, prev = -1, result = 0
    // l = 0, r = 1 prev = 0 result = 0
    // l = 0, r = 2 prev = 1 result = 1
    // l = 1, r = 3 prev = 0 result = 2
    // l = 2, r = 4 prev = 1 result = 3
    // r = 5

};