class Solution {
public:
    // bfs
    // time: O(mn) -> we traverse at most whole image
    // space: O(mn) -> we have a queue
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        if (sr >= m || sr < 0 || sc >= n || sc < 0)
            return {{}};

        int originalColor = image[sr][sc];
        // one edge case is that if the color already the same
        // then we don't even start the bfs
        if (originalColor == color)
            return image;

        const vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int,int>> bfs;
        bfs.push({sr, sc});
        image[sr][sc] = color;

        // we don't need to mark visit
        // because we are finding the originalColor
        // we will color it to a new color, it marks visit naturally
        while (!bfs.empty()) {
            const auto [r, c] = bfs.front();
            bfs.pop();

            for (const auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                // check in-bound
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // check same color
                    if (image[nr][nc] == originalColor) {
                        bfs.push({nr, nc});
                        image[nr][nc] = color;
                    }
                }
            }

        }

        return image;
        
    }
};