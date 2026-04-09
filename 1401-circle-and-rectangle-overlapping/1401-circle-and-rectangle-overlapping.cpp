
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

        // 情形 A：矩形完全在圓心的一側（最遠）
        // 當 $x_1$ 與 $x_2$ 同號時（即 $x_1 \cdot x_2 > 0$），
        // 代表矩形整個落在 $Y$ 軸的左側或右側。此時，離圓心最近的 $x$ 距離一定是 $\min(x_1^2, x_2^2)$。

        // 情形 B：圓心在矩形的 $x$ 範圍內（跨越座標軸）
        // 當 $x_1$ 與 $x_2$ 異號或其中之一為 0 時（即 $x_1 \cdot x_2 \le 0$），
        // 代表矩形橫跨了 $Y$ 軸。此時，矩形上離圓心最近的 $x$ 座標點其實就在 $x=0$ 的位置，因此 $minX = 0$。

        // 情形 C：圓心在矩形內部
        // 如果 $x$ 方向和 $y$ 方向都跨越了座標軸（$minX=0$ 且 $minY=0$），
        // 則 $0 + 0 \le r^2$ 必定成立，正確反映了圓心在矩形內部的重疊狀態。

        int minXsquared = x1 * x2 > 0 ? min(x1*x1, x2*x2) : 0;
        int minYsquared = y1 * y2 > 0 ? min(y1*y1, y2*y2) : 0;
        return minYsquared + minXsquared <= radius * radius;

    }
};