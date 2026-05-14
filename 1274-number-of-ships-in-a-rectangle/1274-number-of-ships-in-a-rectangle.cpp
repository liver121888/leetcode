/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

// if there is at least one ship in the rectangle represented by the two points, 
// including on the boundary.
// we can get the exact number until we have the topRight point == bottomLeft point
// if this is true then we know there is one point

class Solution {
public:

    Sea* sea_;

    int helper(vector<int> topRight, vector<int> bottomLeft) {

        // hasShips is a true false
        // we can call and see if we can rule out certain portion
        // only dfs into the portion that has ship
        // we can divide and conquer the question

        int startX = bottomLeft[0];
        int startY = bottomLeft[1];
        int endX = topRight[0];
        int endY = topRight[1];
        int midY = (endY + startY)/2;
        int midX = (endX + startX)/2;

        // cout << startX << " " << startY << " / " << endX << " " << endY << " / "<< midX << " " << midY <<  endl;
        // 0 0 1 1 
        // mid 0 0 

        // invalid
        if (startX > endX || startY > endY) return 0;
        
        if (!sea_->hasShips(topRight, bottomLeft)) return 0;
        if (startX == endX && startY == endY) return 1;

        // 1 2
        // 3 4
        // 正確原因是：這題 rectangle 是 inclusive boundary，所以切區間時要用 mid + 1 避免重疊。
        // 確實

        int result = 0;

        // area 3
        // if (sea_->hasShips({midX, midY}, {startX, startY})) {
        result += helper({midX, midY}, {startX, startY});
        // }

        // area 2
        // if (sea_->hasShips({endX, endY}, {midX+1, midY+1})) {
        result += helper({endX, endY}, {midX+1, midY+1});
        // }

        // area 1
        // if (sea_->hasShips({midX, endY}, {startX, midY+1})) {
        result += helper({midX, endY}, {startX, midY+1});
        // }

        // area 4
        // if (sea_->hasShips({endX, midY}, {midX+1, startY})) {
        result += helper({endX, midY}, {midX+1, startY});
        // }

        return result;
    }



    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {

        sea_ = &sea;
        return helper(topRight, bottomLeft);
    }
};