// the input is always bottom-left, and top right
// the area is l1*w1 + l2*w2 - overlap
// we can compare and find the 


class Solution {
public:

    bool checkOverlap(int a1, int a2, int b1, int b2) {
        return min(a2, b2) > max(a1, b1);
    }



    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int w1 = ax2 - ax1;
        int h1 = ay2 - ay1; 
        int w2 = bx2 - bx1;
        int h2 = by2 - by1;

        int ho = 0, wo = 0;
        // we need to first check overlap
        if (checkOverlap(ax1, ax2, bx1, bx2) && checkOverlap(ay1, ay2, by1, by2)) {
            ho = min(ay2, by2) - max(ay1, by1);
            wo = min(ax2, bx2) - max(ax1, bx1);
        }


        // ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
        // 6 *4 + 9 * 3 - 6 = 24 + 27 - 6 = 45
        // ho = 2
        // wo = 3 - 0


        // ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2

        // ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -1, by1 = -1, bx2 = 1, by2 = 1

        // cout << w1 << " " << h1 << " " << w2 << " " << h2 << " " << wo << " " << ho << endl;
        return w1*h1+w2*h2-wo*ho;
        
    }
};