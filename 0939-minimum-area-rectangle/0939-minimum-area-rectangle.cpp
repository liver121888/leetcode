// group by x y coords

// check whether we need to return -1
// [[1,1],[1,3],[3,1],[3,3],[2,2]]
// id [0, 1, 2, 3, 4]

// x: {1: {0, 1}, 2: {4}, 3: {2, 3}}
// y: {1: {0, 2}, 2: {4}, 3: {1, 3}}

// [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]

// x: {1: {0, 1}, 4: {4, 5}, 3: {2, 3}}
// y: {1: {0, 2, 4}, 3: {1, 3, 5}}

// 1, 3 -> 0123, 1,4->0145   4, 3-> 2345
// 1, 3 -> 012345

// find max and min x -> we shrinking
// we start with max x = 4, min 1
// we 
// find max and min y -> we shrinking

// we ignore the group with size 1
// unique, shared between x group and y group 

// and at least two points are in each group
// we can form a rectangle
// we check the area of the rectangle
// abs(x1 - x2) * abs(y1 - y2)

// pick 4 points
// check if they can form rectangle
// we chekc the area
// and find the minimum
// time: from n we choose 4 -> n!


// 任意兩點當對角線 → 另外兩點座標可直接算出 → 查是否存在。
// 神鬼技法
// Note : 
// In C++, we use Unordered Map & Unordered Set because there is no need to sort the values inside the map or set. 
// Using Ordered Map & Ordered Set would give TLE (Time Limit Exceeded), because those data structures consume 
// time for  unnecessary internal sorting
// Time Complexity : O(n^2)
// where n = Total number of points
// Explanation :
// Iteration Time: Iterating through different (A,B) pairs => O(n^2)
// Search Time: Searching for y coordinate corresponding to x coordinate => 
// O(n) {Worst case for searching in HashSet} + O(n) {Worst case for searching in HashMap} => O(n)
// Time Complexity = Iteration Time * Search Time, since we are searching for point C & D for each pair of point A & B
// So in this case the time complexity will be O(n^2) * O(n) = O(n^3)
// But usually, we consider the search operation in a HashMap & HashSet to run in constant time i.e. O(1).
// Hence the time complexity will be O(n^2) * O(1) = O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> hashmap; // Key => Integer | Value => Set
        
        for(auto& single_point: points) // Iterate through every single point & store the coordinates in map.
            hashmap[single_point[0]].insert(single_point[1]); 
            // Insert y coordinate into Value (HashSet) corresponding to Key (equal to x coordinate)
			// Explanation : 
			//		single_point => refering to a single point [x,y] in vector
			//		x-coordinate of a single point => single_point[0]
			//		y-coordinate of a single point => single_point[1]

			//		Key => x coordinate of a point 
			//			=> single_point[0]

			//		Value => HashSet of y coordinates 
			//			=> hashmap[Key]
			//			=> hashmap[x-coordinate of a single point]
			//			=> hashmap[single_point[0]]

			//		Insert y coordinate into corresponding Value (HashSet)
			//			=> Value.insert(y-coordinate of a single point)
			//			=> hashmap[Key].insert(y-coordinate of a single point)
			//			=> hashmap[x-coordinate of a single point].insert(y-coordinate of a single point)
			//			=> hashmap[single_point[0]].insert(single_point[1])
			
        int minimum_area = INT_MAX; // Vairable to store the minimum area
        
        for(int i = 0; i < points.size(); i++) { // Iterator corresponding to different A points
            for(int j = i + 1; j < points.size(); j++) { // Iterator corresponding to different B points
			
                int x1 = points[i][0], y1 = points[i][1];  // Coordinates of Point A
				int x2 = points[j][0], y2 = points[j][1];  // Coordinates of Point B
                
                if(x1 != x2 && y1 != y2) // Point A & B must form a diagonal of the rectangle.
                    if(hashmap[x1].find(y2) != hashmap[x1].end() // Check if D exists in hashmap
											&& 
					hashmap[x2].find(y1) != hashmap[x2].end() ) // Check if C exists in hashmap
					// Explanation : 
					//		Check existence of y2 in Value (HashSet) corresponding to x1 Key
					//			=> Value.find(y-coordinate of point B)
					//			=> hashmap[Key].find(y-coordinate of point B)
					//			=> hashmap[x-coordinate of point A].find(y-coordinate of point B)
					//			=> hashmap[x1].find(y2) => Checks if point D exists in hashmap 
					//		Check existence of y1 in Value (HashSet) corresponding to x2 Key
					//			=> Value.find(y-coordinate of point A)
					//			=> hashmap[Key].find(y-coordinate of point A)
					//			=> hashmap[x-coordinate of point B].find(y-coordinate of point A)
					//			=> hashmap[x2].find(y1) => Checks if point C exists in hashmap 

                    minimum_area = min(minimum_area , abs(x1-x2) * abs(y1-y2)); // Store the minimum area possible
            }
        }
        return minimum_area != INT_MAX ? minimum_area : 0; // Return 0 if no rectangle exists
    }
};

// 取垂直線技法
// 直覺（不用畫圖也很好記）
// 固定一個 x（一條垂直線），上面有很多 y。
// 只要在兩個不同的 x 上都出現同一組 (y1, y2)，就形成一個矩形：
// 左邊 x = x_old 也有 y1,y2
// 右邊 x = x_now 也有 y1,y2
// 面積 = (x_now - x_old) * (y2 - y1)
// 所以我們對每個 x，枚舉它上面的所有 y-pair，把它當 key，記住「上一次看到它的 x」。

// #include <bits/stdc++.h>
// using namespace std;

// struct PairHash {
//     size_t operator()(const pair<int,int>& p) const noexcept {
//         return ( (uint64_t)(uint32_t)p.first << 32 ) ^ (uint32_t)p.second;
//     }
// };

// class Solution {
// public:
//     int minAreaRect(vector<vector<int>>& points) {
//         map<int, vector<int>> xs;
//         for (auto &p : points) xs[p[0]].push_back(p[1]);

//         unordered_map<pair<int,int>, int, PairHash> lastx;
//         lastx.reserve(points.size() * 4);

//         long long ans = LLONG_MAX;

//         for (auto &kv : xs) {
//             int x = kv.first;
//             auto &ys = kv.second;
//             sort(ys.begin(), ys.end());

//             for (int i = 0; i < (int)ys.size(); i++) {
//                 for (int j = i + 1; j < (int)ys.size(); j++) {
//                     int y1 = ys[i], y2 = ys[j];
//                     pair<int,int> key = {y1, y2};

//                     auto it = lastx.find(key);
//                     if (it != lastx.end()) {
//                         ans = min(ans, 1LL * (x - it->second) * (y2 - y1));
//                     }
//                     lastx[key] = x;
//                 }
//             }
//         }

//         return ans == LLONG_MAX ? 0 : (int)ans;
//     }
// };