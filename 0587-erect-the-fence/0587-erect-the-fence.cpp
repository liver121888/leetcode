

// Jarvis Algorithm
// Time complexity : O(m∗n)
// Space complexity : O(m)
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int orientation(vector<int>& p, vector<int>& q, vector<int>& r) {
//         return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
//     }

//     bool inBetween(vector<int>& p, vector<int>& i, vector<int>& q) {
//         bool a = (i[0] >= p[0] && i[0] <= q[0]) || (i[0] <= p[0] && i[0] >= q[0]);
//         bool b = (i[1] >= p[1] && i[1] <= q[1]) || (i[1] <= p[1] && i[1] >= q[1]);
//         return a && b;
//     }

//     vector<vector<int>> outerTrees(vector<vector<int>>& points) {
//         set<vector<int>> hull;
//         if (points.size() < 4) {
//             for (const auto& p : points)
//                 hull.insert(p);
//             vector<vector<int>> result(hull.begin(), hull.end());
//             return result;
//         }

//         int left_most = 0;
//         for (int i = 0; i < points.size(); i++) {
//             if (points[i][0] < points[left_most][0]) {
//                 left_most = i;
//             }
//         }
        
//         int p = left_most;
//         do {
//             int q = (p + 1) % points.size();
//             for (int i = 0; i < points.size(); i++) {
//                 if (hull.find(points[i]) != hull.end())
//                     continue;
                
//                 if (orientation(points[p], points[i], points[q]) < 0) {
//                     q = i;
//                 }
//             }

//             for (int i = 0; i < points.size(); i++) {
//                 if (i != p && i != q && orientation(points[p], points[i], points[q]) == 0 && inBetween(points[p], points[i], points[q])) {
//                     hull.insert(points[i]);
//                 }
//             }

//             hull.insert(points[q]);
//             p = q;
//         } while (p != left_most);

//         vector<vector<int>> result(hull.begin(), hull.end());
//         return result;
//     }
// };

// Approach 2: Graham Scan
// Time complexity : O(nlogn)
// Space complexity : O(n)

// class Solution {
// public:

//     vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
//     }
// };

// Approach 3: Monotone Chain
// Time complexity : O(nlogn)
// Space complexity : O(n)

// In this algorithm, we consider the hull as being comprised of two sub-boundaries- The upper hull and the lower hull. 
// We form the two portions in a slightly different manner.
// We traverse over the sorted points array after adding the initial two points in the hull 
// temporarily (which are pushed over the stack hull). For every new point considered, 
// we check if the current point lies in the counter-clockwise direction relative to the last 
// two points. If so, the current point is immediately pushed onto hull. If not(indicated by a 
// positive orientation), we again get the inference that the last point on the hull needs to lie 
// inside the boundary and not on the boundary. Thus, we keep on popping the points from hull till the current point 
// lies in a counterclockwise direction relative to the top two points on the hull.
// Note that this time, we need not consider the case of collinear points explicitly, 
// since the points have already been sorted based on their x-coordinate values. 
// So, the collinear points, if any, will implicitly be considered in the correct order.

#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // why?
    // imagine 3 points on the plane
    //      r
    //     /
    //    /
    //   p
    //    \
    //     \
    //      q
    // 從 $p$ 走到 $q$，再從 $q$ 走到 $r$
    // pq x qr > 0 cross product should be larger than 0 it means z pointing outward
    // 透過外積算出來的值，我們可以判斷轉彎方向：外積 > 0 (左轉 / 逆時針)：代表 $r$ 在外側（凸出），這正是凸包需要的形狀！
    // 外積 < 0 (右轉 / 順時針)：代表 $q$ 凹進去了。這時我們必須把 $q$ 從目前的凸包中移除（Pop），因為它不可能在最外圍。
    // 外積 = 0 (共線 / 直走)：三點在一條直線上。
    // then (qx​−px​)∗(ry​−qy​)−(qy​−py​)∗(rx​−qx​) > 0
    int orientation(const vector<int>& p, const vector<int>& q, const vector<int>& r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& points) {

        int n = points.size();
        // 如果點的數量小於等於 3，所有的點一定都在凸包上，直接回傳即可
        if (n <= 3) 
            return points;

        // 1. 排序：先比 x (由小到大)，如果 x 相同則比 y (由小到大)
        // 這是為了確保我們從最左邊的點開始，往右建立單調鏈
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        // 我們使用 vector 來當作 Stack，因為這樣才能方便取得「倒數第二個」元素
        vector<vector<int>> hull;

        // 2. 建構下半部凸包 (Lower Hull)
        for (int i = 0; i < n; i++) {
            // 如果外積 < 0 (發生右轉/凹陷)，代表目前 stack 頂端的點不合格，需要 pop 掉
            while (hull.size() >= 2 && 
                   orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        // 3. 建構上半部凸包 (Upper Hull)
        // 從最右邊的點往左邊走回去
        int lower_size = hull.size(); // 記錄下半部的大小，避免 pop 到下半部的點
        
        for (int i = n - 2; i >= 0; i--) {
            while (hull.size() > lower_size && 
                   orientation(hull[hull.size() - 2], hull.back(), points[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        // 移除最後一個點，因為它和起點是同一個點（繞了一圈回來）
        hull.pop_back();

        // 4. 使用 set 來消除可能重複的點，確保結果乾淨
        // (例如有很多點在同一條直線上時，來回可能會重複收錄)
        set<vector<int>> unique_points(hull.begin(), hull.end());
        
        // 將 set 轉回 vector 並回傳
        return vector<vector<int>>(unique_points.begin(), unique_points.end());
    }
};
