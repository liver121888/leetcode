
// some intuitions
// square, all of it's point's x y will not exceed x1 y1 x2 y2
// circle, all of it's point will not exceed radius

// Locate the closest point of the square to the circle, then check that point's
// dist to the center

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        // Transform (x_center,y_center) to (0,0)
        // so we modify square coords
        x1 -= xCenter; 
        x2 -= xCenter;
        y1 -= yCenter; 
        y2 -= yCenter;

        // Check if x1 and x2 are both in same side of y axis(left and right side)
        // If not then min possible point lies on y-axis.
        int minX = x1 * x2 > 0 ? min(x1*x1, x2*x2) : 0;
        int minY = y1 * y2 > 0 ? min(y1*y1, y2*y2) : 0;
        return minY + minX <= radius * radius;

    }
};