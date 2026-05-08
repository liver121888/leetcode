class Solution {
public:

    unordered_map<string, int> memo;

    int dfs(int x, int y) {

        string hash = to_string(x) + " " + to_string(y);
        if (memo.find(hash) != memo.end())
            return memo.at(hash);

        // two options
        // x -1 y -2
        // x -2 y -1
        // base cases
        if (x + y == 0) {
            return 0;
        } else if (x + y == 2) {
            return 2;
        } 
        
        // abs here: 我反向跳一步後，如果跳到負座標，不要真的去處理負座標，因為它跟對稱的正座標答案一樣。
        int option1 = dfs(abs(x - 1), abs(y - 2));
        int option2 = dfs(abs(x - 2), abs(y - 1));
        memo[hash] = min(option1, option2) + 1;
        return memo[hash];

    }

    int minKnightMoves(int x, int y) {

        return dfs(abs(x), abs(y));
    }
};