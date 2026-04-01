

// Bellman ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX / 2);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> next = dist;
            for (const auto& f : flights) {
                int from = f[0];
                int to = f[1];
                int price = f[2];

                next[to] = min(next[to], dist[from] + price);
            }
            dist = next;
        }

        return dist[dst] >= INT_MAX / 2 ? -1 : dist[dst];
    }
};


// this is WRONG
// because we only track the cost but not the stops
// 有可能high cost但k站內抵達
// 如果只看dijkstra cost就可能rule out possible ans
// 應該用dijkstra但 save minStops
// 然後track cost using the other field

// class Solution {
// public:

//     // with at most k stops
//     // we have to dijkstra with constraint

//     // we can have a minPrice array to store the min cost
//     // but we also need to compare the stop
//     // because if we reach a node with the same price, we need to select the one with 
//     // lower stops
//     // it will be great to have a pq with custom comparator

//     // n cities are marked from 0 - n-1
//     // judging by the range, we know the cost cannot > int_max, so it's safe to use int

//     // 0 -> 1 1
//     // 0 -> 2 5
//     // 1 -> 2 1
//     // 2 -> 3 1
//     // ok so the situation is reachable within k but with high cost
//     // how can I solve?
//     // should I dijksta twice?
//     // no, I can bfs once to see if I can reach within k
//     // then check for the cost

//     struct node {
//         int city;
//         int priceTotal;
//         int stopTaken;

//         // 你 overload 的 operator< 是在定義 node 本身誰比較小，
//         // 但 priority_queue 預設要的是 誰應該當最大、放在 top。
//         // 所以直接拿 operator< 來湊 min-heap 很容易語意打架；
//         // custom comparator 則是直接在定義 heap 規則，所以更清楚也更容易過。
//         // const means this member function will NOT modify the current object (this)
//         // bool operator<(const node& other) const {
//         //     if (priceTotal != other.priceTotal)
//         //         return priceTotal > other.priceTotal;

//         //     return stopTaken > other.stopTaken;
//         // }

//     };

//     struct compare {
//         // we want a minHeap, lower priority at front
//         // thus here we need to flip the sign
//         bool operator()(const node& a, const node& b) const {
//             if (a.priceTotal != b.priceTotal)
//                 return a.priceTotal > b.priceTotal;

//             return a.stopTaken > b.stopTaken;

//         }
//     };

//     // time: O(n + e) travers graph and traverse edge to build adjLists
//     // space: O(n + e) for pq and adjlist

//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
//         // build adjLists
//         // city/cost
//         vector<vector<pair<int,int>>> adjLists(n, vector<pair<int,int>>());
//         for (const auto& flight : flights) {
//             adjLists[flight[0]].emplace_back(flight[1], flight[2]);
//         }


//         if (!bfs(adjLists, src, dst, k))
//             return -1;

//         // costArray
//         vector<int> minPrice(n, INT_MAX/2);

//         priority_queue<node, vector<node>, compare> pq;

//         pq.push({src, 0, 0});
//         minPrice[src] = 0;

//         while (!pq.empty()) {
//             const auto curr = pq.top();
//             pq.pop();

//             if (curr.priceTotal != minPrice[curr.city])
//                 continue;

//             if (curr.city == dst)
//                 break;

//             for (const auto& [neighborCity, price] : adjLists[curr.city]) {
//                 if (curr.priceTotal + price < minPrice[neighborCity] 
//                     && curr.stopTaken <= k) {
//                     minPrice[neighborCity] = curr.priceTotal + price;
//                     // id, priceTotal, stopTaken
//                     pq.push({neighborCity, curr.priceTotal + price, curr.stopTaken + 1});
//                 }

//             }

//         }
//         return minPrice[dst] == INT_MAX/2 ? -1 : minPrice[dst];

//     }
// };

