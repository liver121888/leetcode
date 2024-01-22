class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] > 0) {
                    int top; 
                    int left;

                    if (i == 0)
                        top = 1e5;
                    else
                        top = mat[i - 1][j];

                    if (j == 0)
                        left = 1e5;
                    else
                        left = mat[i][j - 1];

                    mat[i][j] = min(top, left) + 1;  
                }
            }            
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] > 0) {
                    int bottom = (i < m - 1) ? mat[i + 1][j] : 1e5;
                    int right = (j < n - 1) ? mat[i][j + 1] : 1e5;
                    mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
                }
            }
        }
        
        
        return mat;
    }
    
};