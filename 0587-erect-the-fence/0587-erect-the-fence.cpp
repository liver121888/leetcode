

// Jarvis Algorithm
// Time complexity : O(m∗n)
// Space complexity : O(m)
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
    }

    bool inBetween(vector<int>& p, vector<int>& i, vector<int>& q) {
        bool a = (i[0] >= p[0] && i[0] <= q[0]) || (i[0] <= p[0] && i[0] >= q[0]);
        bool b = (i[1] >= p[1] && i[1] <= q[1]) || (i[1] <= p[1] && i[1] >= q[1]);
        return a && b;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        set<vector<int>> hull;
        if (points.size() < 4) {
            for (const auto& p : points)
                hull.insert(p);
            vector<vector<int>> result(hull.begin(), hull.end());
            return result;
        }

        int left_most = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] < points[left_most][0]) {
                left_most = i;
            }
        }
        
        int p = left_most;
        do {
            int q = (p + 1) % points.size();
            for (int i = 0; i < points.size(); i++) {
                if (hull.find(points[i]) != hull.end())
                    continue;
                
                if (orientation(points[p], points[i], points[q]) < 0) {
                    q = i;
                }
            }

            for (int i = 0; i < points.size(); i++) {
                if (i != p && i != q && orientation(points[p], points[i], points[q]) == 0 && inBetween(points[p], points[i], points[q])) {
                    hull.insert(points[i]);
                }
            }

            hull.insert(points[q]);
            p = q;
        } while (p != left_most);

        vector<vector<int>> result(hull.begin(), hull.end());
        return result;
    }
};


// class Solution {
// public:

//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
//     }
// };