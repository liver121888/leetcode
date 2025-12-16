class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        // this is a grap problem and we can solve it with bfs

        int m = image.size();
        int n = image[0].size();

        int oc = image[sr][sc];
        if (oc == color)
            return image;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> bfs;
        image[sr][sc] = color;
        bfs.push(make_pair(sr, sc));
        // r, c
        while(!bfs.empty()){
            pair<int, int> aPair = bfs.front();
            cout << aPair.first << " " << aPair.second << endl;
            bfs.pop();
            for (auto dir : directions) {
                int nr = aPair.first + dir.first;
                int nc = aPair.second + dir.second;
                // boundary check
                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                if (image[nr][nc] == oc) {
                    image[nr][nc] = color;
                    bfs.push(make_pair(nr, nc));
                }
            }
        }
        return image;
    }
};

// int main(vector<vector<int>>& map, int sr, int sc, int color) {


//     return ans;
// }