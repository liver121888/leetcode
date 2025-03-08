class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int l = 0;
        int minOp = INT_MAX;

        int curOp = 0;
        for (int r = 0; r < blocks.size(); r++) {
            curOp += blocks[r] == 'B' ? 0 : 1;

            if (r - l + 1 > k) {
                curOp -= blocks[l] == 'B' ? 0 : 1;
                l++;
            }

            if (r - l + 1 == k) {
                minOp = min(curOp, minOp);
            }
        }
        return minOp;
    }
};

// "WBWBBBW"
// l = 0 r = 0 curOp = 0 minOp = 0
// minOp = 1