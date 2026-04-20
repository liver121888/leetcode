
// Return the maximum distance between two houses with different colors.
// we can have unordered map
// same color record min max
// then take the max of the abs values
// this is not good to implement because you might face the rightmost
// and leftmost are the same color

// n == colors.length
// 2 <= n <= 100
// 0 <= colors[i] <= 100
// Test data are generated such that at least two houses have different colors.

// [1,1,1,6,1,1,1]

// 1: {0, 6}
// 6: {3, 3}

// [1,8,3,8,3]
// 1: 0, 0
// 8: 1, 3
// 3: 2, 4


class Solution {
public:
    int maxDistance(vector<int>& colors) {

        // Greedily, the maximum distance will come from either the pair 
        // of the leftmost house and possibly some house on the right with a 
        // different color, or the pair of the rightmost house and possibly some 
        // house on the left with a different color.

        int n = colors.size();
        int leftMostColor = colors[0], rightMostColor = colors[n-1];

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != rightMostColor) {
                result = max(result, n - 1 - i);
                break;
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (colors[i] != leftMostColor) {
                result = max(result, i);
                break;
            }
        }

        return result;
        
        // unordered_map<int, pair<int,int>> record;

        // for (int i = 0; i < colors.size(); i++) {
        //     int color = colors[i];
        //     if (record.find(color) != record.end()) {
        //         record[color] = {record.at(color).first, i};
        //     } else {
        //         record[color] = {i, i};
        //     }
        // }
        // for (const auto& [c, indices] : record) {
        //     indices[0];
        //     indices[1];
        // }

        // return 
    }
};