// class Solution {
// public:
//     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
//     }
// };


class Solution {

public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        int n = routes.size();
        // vector<unordered_set<int>> route2stop(n);
        unordered_map<int, vector<int>> stop2route;

        // 1: 2,3
        // group2 can go to these stops
        // 8 5 9 7 1 4 5 4 ... 20000..  7 8 4 6

        // for bfs initial positions
        for (int i = 0; i < n; i++) {
            for (auto stopid : routes[i]) {
                stop2route[stopid].push_back(i);
            }
        }

        // start bfs from the start groups
        // number of groups we traversed / group id
        queue<int> bfs;
        // visited groups
        unordered_set<int> visitedRoute;
            
        // visit the group
        bfs.push(source);

        int layer = 0;
        while (!bfs.empty()) {

            int currLayerSize = bfs.size();
            while (currLayerSize) {
                auto currStop = bfs.front();
                bfs.pop();

                if (currStop == target)
                    return layer;

                for (auto route : stop2route[currStop]) {
                    if (visitedRoute.find(route) != visitedRoute.end())
                        continue;
                    visitedRoute.insert(route);
                    for (int neighborStop : routes[route]) {
                        bfs.push(neighborStop);
                    }
                }
                currLayerSize--;
            }
            layer++;
        }
        return -1;

    }

};
