class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        int curSum = 0;
        int cnt = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                curSum = 0;
                cnt = 0;

                // Iterate over all plausible nine indices.
                for (int y = i - 1; y <= i + 1; y++) {
                    for (int x = j - 1; x <= j + 1; x++) {
                        // If the indices form valid neighbor
                        if (0 <= y && y < m && 0 <= x && x < n) {
                            curSum += img[y][x];
                            cnt += 1;
                        }
                    }
                }
                
                // Store the rounded down value in smoothImg[i][j].
                ans[i][j] = curSum/cnt;
            }
            
        }
        return ans;
        
    }
};