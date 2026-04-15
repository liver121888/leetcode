

// check if the dx dy is the same
// handle case that vertical and horizontal
class Solution {
public:

    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x1, y1, x2, y2;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        x2 = coordinates[1][0];
        y2 = coordinates[1][1];
        for (int i = 2; i < coordinates.size(); i++)
        {
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            // use multiplication to avoid divide 
            if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1))
                return false;
        }
        return true;
    }


    // Returns the delta Y.
    // int getYDiff(vector<int>& a, vector<int>& b) {
    //     return a[1] - b[1];
    // }
    
    // // Returns the delta X.
    // int getXDiff(vector<int>& a, vector<int>& b) {
    //     return a[0] - b[0];
    // }
    
    // bool checkStraightLine(vector<vector<int>>& coordinates) {
    //     int deltaY = getYDiff(coordinates[1], coordinates[0]);
    //     int deltaX = getXDiff(coordinates[1], coordinates[0]);
        
    //     for (int i = 2; i < coordinates.size(); i++) {
    //         // Check if the slope between points 0 and i, 
    //         // is the same as between 0 and 1.
    //         if (deltaY * getXDiff(coordinates[i], coordinates[0])
    //             != deltaX * getYDiff(coordinates[i], coordinates[0])) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};