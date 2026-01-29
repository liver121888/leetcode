class Solution {
public:

    string hash(int y, int x) {
        string hashStr = to_string(y) + " " + to_string(x);
        return hashStr;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int direction = 0;

        int yDirs[4] = {1, 0, -1, 0};
        int xDirs[4] = {0, 1, 0, -1};

        unordered_set<string> obs;
        for (auto obstacle : obstacles)
            obs.insert(hash(obstacle[1], obstacle[0]));

        int maxDist = 0;
        int currY = 0;
        int currX = 0;

        for (auto command : commands) {

            if (command == -1) {
                direction = ((direction + 1) + 4) % 4;
            } else if (command == -2) {
                direction = ((direction - 1) + 4) % 4;
            } else {
                
                while (command) {
                    int ny = currY + yDirs[direction];
                    int nx = currX + xDirs[direction];

                    // cout << ny << "/" << nx << endl;
                    
                    // face obstacle
                    string hashStr = hash(ny, nx);

                    if (obs.find(hashStr) != obs.end()) {
                        break;
                    }
                    currY = ny;
                    currX = nx;
                    command--;
                }
            }
            // cout << currY << " " << currX << " " << direction << endl;
            maxDist = max(maxDist, currY * currY + currX * currX);
        }

        return maxDist;
    }
};