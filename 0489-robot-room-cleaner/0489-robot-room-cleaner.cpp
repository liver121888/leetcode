/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */


// we need to come up with an algo to guaranteed to clean the room
// I assume the grid is always valid for the robot to clean
// i.e. no blocked empty region

// if right is empty -> go to right and clean
// be sure to remember the step we took
// top -> left -> down -> right
// This solution is based on the same idea as the solving algorithm called right-hand rule. 


class Solution {
public:

    const int directions[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    unordered_set<string> visited;

    Robot* robotPtr;

    void goBack() {
        robotPtr->turnRight();
        robotPtr->turnRight();
        robotPtr->move();
        robotPtr->turnRight();
        robotPtr->turnRight();
    }

    void backtrack(int row, int col, int d) {
        visited.insert(to_string(row) + " " + to_string(col));
        robotPtr->clean();
        // going clockwise : 0: 'up', 1: 'right', 2: 'down', 3: 'left'
        for (int i = 0; i < 4; ++i) {
            int newD = (d + i) % 4;
            int newRow = row + directions[newD][0];
            int newCol = col + directions[newD][1];

            if (!visited.count(to_string(newRow) + " " + to_string(newCol)) && robotPtr->move()) {
                backtrack(newRow, newCol, newD);
                goBack();
            }
            // turn the robot following chosen direction : clockwise
            robotPtr->turnRight();
        }

    }


    void cleanRoom(Robot& robot) {
        robotPtr = &robot;
        backtrack(0, 0, 0);
    }
};