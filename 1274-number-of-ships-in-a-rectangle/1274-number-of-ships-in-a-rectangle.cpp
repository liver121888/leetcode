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

// Let M be the range of possible x-coordinate values between bottomLeft[0] and topRight[0] and let N be the range of possible y-coordinate values 
// between bottomLeft[1] and topRight[1]. Thus, the maximum possible number of points in the rectangle is M⋅N. Finally, 
// let S be the maximum number of ships in the sea.

// Time Complexity: O(S⋅(log_2(max(M,N))−log_4(S)))
// Space Complexity: O(log_2(max(M,N))), recursion call stack 

// 為什麼是減掉 log_4(S)？
// 整個 recursion 最大深度是：
// log_2(max(M, N))
// 因為每次 x/y range 都大約砍半。
// 但是前面這些層：
// log_4(S)
// 是在「把 S 艘船分散到不同區塊」的過程。
// 之後才進入這個狀態：
// 每個 non-empty region 裡面最多只有 1 艘船
// 一旦一個區域裡只有 1 艘船，剩下的事情就是繼續二分/四分，直到精確找到那個 ship 的座標。
// 所以每艘船後面還需要走的深度大概是：
// total depth - already split depth
// 也就是：
// log_2(max(M, N)) - log_4(S)
// 這就是 -log_4(S) 的來源。

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