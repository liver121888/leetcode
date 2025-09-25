// class Solution {
// public:

//     int n = 0;
//     int ans = INT_MAX;
//     unordered_map<pair<int, int>, int> minSum;

//     // in every layer, at current state, we have two options
//     // to define the state
//     // currentSum, currentIdx, currLayer

//     void dfs(const vector<vector<int>>& triangle, int currSum, int currIdx, int currLayer)  {

//         // cout << "currSum: " << currSum << ", currIdx: " << currIdx << ", currLayer: " << currLayer << endl; 

//         // base cases, when we step out of the depth (n) of the triangle
//         if (currLayer == n) {
//             ans = min(ans, currSum);
//             return;
//         }
        
//         auto triLayer = triangle[currLayer];
//         int width = triLayer.size();

//         // edge cases, should not happen
//         if (currIdx < 0 || currIdx == width) {
//             cout << "Should not happen" << endl;
//             return;
//         }

//         // two options

//         // we take index i
//         dfs(triangle, currSum + triLayer[currIdx], currIdx, currLayer+1);

//         // or we take index i + 1
//         dfs(triangle, currSum + triLayer[currIdx], currIdx + 1, currLayer+1);

//     }


//     // 0, 0, 0
//     // [2], 1
//     // dfs(2, 0, 1)
//         // 

//     // dfs(2, 1, 1)


//     int minimumTotal(vector<vector<int>>& triangle) {

//         // simulation
//         // we compare all the possibilities

//         // we reach the leaf nodes when currLayer = n - 1
//         n = triangle.size();
        
//         dfs(triangle, 0, 0, 0);

//         return ans;
//     }
// };




class Solution {
public:
    int n = 0;
    unordered_map<string, int> memo; // Use string key for simplicity
    
    // Returns minimum sum from position (currIdx, currLayer) to bottom
    int dfs(const vector<vector<int>>& triangle, int currIdx, int currLayer) {
        // Base case: reached bottom
        if (currLayer == n) {
            return 0;
        }
        
        // Create key for memoization
        string key = to_string(currIdx) + "," + to_string(currLayer);
        
        // Check if already computed
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // Current value at this position
        int currentVal = triangle[currLayer][currIdx];
        
        // Two choices: go to currIdx or currIdx+1 in next layer
        int choice1 = dfs(triangle, currIdx, currLayer + 1);
        int choice2 = dfs(triangle, currIdx + 1, currLayer + 1);
        
        // Store and return minimum
        memo[key] = currentVal + min(choice1, choice2);
        return memo[key];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memo.clear();
        return dfs(triangle, 0, 0);
    }
};