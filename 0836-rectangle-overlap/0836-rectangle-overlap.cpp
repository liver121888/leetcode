

// To be clear, two rectangles that only touch at the corner or edges do not overlap.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int x1A = rec1[0]; int y1A = rec1[1]; int x2A = rec1[2]; int y2A = rec1[3];        
        int x1B = rec2[0]; int y1B = rec2[1]; int x2B = rec2[2]; int y2B = rec2[3];

        if (max(x1A, x1B) < min(x2A, x2B) && max(y1A, y1B) < min(y2A, y2B))
            return true;
        return false;
    }
};