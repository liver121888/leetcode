class Solution {
public:
    int ans = 0;
    int rx = 0;
    int ry = 0;
    // N
    int facing = 0;
    
    // Slightly larger than 2 * max coordinate value
    static const int HASH_MULTIPLIER = 60013;

    // Hash function to convert (x, y) coordinates to a unique integer value
    int hashCoordinates(int x, int y) { return x + HASH_MULTIPLIER * y; }
    
    // N W S E
    vector<vector<int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(hashCoordinates(obstacle[0], obstacle[1]));
        }        
        
        for (int command : commands) {
            
            if (command == -1) {
                // Turn right
                facing = (facing + 3) % 4;
                continue;
            }
            if (command == -2) {
                // Turn left
                facing = (facing + 1) % 4;
                continue;
            }
            
            while (command != 0) {
                int x = rx + directions[facing][0];
                int y = ry + directions[facing][1];  
                if (obstacleSet.contains(hashCoordinates(x, y))) {
                    break;
                }
                rx = x;
                ry = y;
                ans = max(ans, rx*rx + ry*ry);
                command -= 1;
            }  
        }               
        return ans;
    }
};