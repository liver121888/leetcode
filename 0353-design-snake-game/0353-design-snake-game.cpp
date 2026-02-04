// in the game
// return the score of the game after the move
// check if game over
// we always starts at 0 0 with size 1

// aside from a move funciton, it is good to have a 
// check game over function

// some mechanism we need
// check if the head collide with the body
// update the body coords (using a queue)
// check if we meet the food
// everytime we return the size of the queue

class SnakeGame {
public:

    // use a queue to represent the snake
    queue<pair<int,int>> snake;

    // use unordered_set to check collision
    unordered_set<string> snakeBody;

    // a hashmap for the direciton
    const unordered_map<string, pair<int,int>> directions = 
        {{"U", {-1, 0}}, {"R", {0, 1}}, {"L", {0, -1}}, {"D", {1, 0}}};
    
    // boundary check
    int w, h;

    // food coords
    queue<pair<int,int>> foods;

    string hash(int y, int x) {
        return to_string(y) + " " + to_string(x);
    }

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;

        // food appears one by one on the screen
        // but we are given the whole food array
        // so we also need a ptr to point the current food
        // it's better to use queue to represent it
        for (const auto& f : food) {
            foods.push({f[0], f[1]});
        }

        // init snake with {0, 0}
        snake.push({0, 0});
        snakeBody.insert(hash(0, 0));
    }
    
    int move(string direction) {

        // apply the move
        // get the head in the back
        auto coords = snake.back();
        int ny = coords.first + directions.at(direction).first;
        int nx = coords.second + directions.at(direction).second;

        cout << "ny: " << ny << " nx: " << nx << endl;

        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            return -1;

        // grow the snake if needed
        // check if there is still food, 
        // then we might need to grow snake

        bool ate = false;
        if (!foods.empty()) {
            auto foodCoords = foods.front();
            if (ny == foodCoords.first && nx == foodCoords.second) {
                ate = true;
                // update food location
                foods.pop();
            }
        } 

        // if didn't find the food, we need to update the snake
        if (!ate) {
            auto coords = snake.front();
            snake.pop();
            snakeBody.erase(hash(coords.first, coords.second));
        }

        // 再做身體碰撞判定
        if (snakeBody.count(hash(ny, nx))) 
            return -1;

        // push in the new coords
        snake.push({ny, nx});
        snakeBody.insert(hash(ny, nx));

        // snake size is the current score
        return snake.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */