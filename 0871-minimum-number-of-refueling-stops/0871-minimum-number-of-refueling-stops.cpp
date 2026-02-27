// 0 -> target

// stations, we need to reutrn the minimum number of refeuling stops


// target = 1, startFuel = 1, stations = []
// Output: 0

// target = 100, startFuel = 1, stations = [[10,100]]
// Output: -1

// Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
// Output: 2

// each stations have different number of fuel, so it's hard to use greedy

// for each station we can choose whether to fuel there
// state of dp remaining fule, and the index of the station, and we store the minimum 
// refueling stops in the dp array
// 0 <= stations.length <= 500

// 1 <= positioni < positioni+1 < target -> stations are sorted
// the minimum refuel to this stop can it contribute to the minimum refeul to next stop
// dp[i][fuel] = min(dp[i-1],dp[i-2], dp[i-3])
// the fuel is like a constraint here
// i is the state

// back tracking first
// each station we see if we can reach
// if we can reach, we decide whether to fuel
// go to the next station from there
// and we compare the minimum refuel stops number in the end
// O(2^n * log(n)) in each station we decide to fuel or not

// target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
// cannot use current_id, we need to serach the next available stop

// dp solution
// This is motivated by the fact that we want the smallest i for which dp[i] >= target.
// dp[k] = 加油 k 次後，最多能到達的最遠距離
// dp[k]

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n + 1);
        // if don't pump gas, we can only go this far
        dp[0] = startFuel;

        // at most we can add gas for n times
        // For example, if we could reach a distance of 15 with 1 refueling stop, 
        // and now we added a station at location 10 with 30 liters of fuel, 
        // then we could potentially reach a distance of 45 with 2 refueling stops.

        // we add station one by one
        for (int i = 0; i < n; i++) {
            for (int t = i; t >= 0; t--) {
                if (dp[t] >= stations[i][0]) {
                    // save the farthest we can go by adding the gas
                    dp[t+1] = max(dp[t+1], (long long) dp[t] + stations[i][1]);
                }

            }
        }

        // find the minimum pump gas times that is larger than target
        for (int i = 0; i <= n; ++i)
            if (dp[i] >= target) 
                return i;
        return -1;

    }
};


// class Solution {
// public:
//     int minStops = INT_MAX;

//     // 回傳「下一個站」index：第一個 stations[i][0] > currLoc
//     // 若不存在，回傳 -1
//     int searchNextStop(const vector<vector<int>>& stations, int currLoc) {
//         int l = 0, r = (int)stations.size(); // 注意：r 用 size，做 upper_bound
//         while (l < r) {
//             int mid = l + (r - l) / 2;
//             if (stations[mid][0] <= currLoc) {
//                 l = mid + 1;
//             } else {
//                 r = mid;
//             }
//         }
//         return (l == (int)stations.size()) ? -1 : l;
//     }

//     void backtrack(const vector<vector<int>>& stations, int currFuel, int numRefuel, 
//         int currLoc, int target) {
//         // 剪枝：已經不可能比目前答案更好
//         if (numRefuel >= minStops) 
//             return;

//         // base case: 可達 target
//         if (currLoc + currFuel >= target) {
//             minStops = min(minStops, numRefuel);
//             return;
//         }

//         int nextStopId = searchNextStop(stations, currLoc);

//         // 沒有下一站了，但又到不了 target
//         if (nextStopId == -1) 
//             return;

//         int stationPos = stations[nextStopId][0];
//         int stationFuel = stations[nextStopId][1];

//         // 到不了下一站
//         if (currLoc + currFuel < stationPos)
//             return;

//         // 移動到下一站
//         int fuelAfterDrive = currFuel - (stationPos - currLoc);
//         int newLoc = stationPos;

//         // 選擇 1：在這站加油
//         backtrack(stations, fuelAfterDrive + stationFuel, numRefuel + 1, newLoc, target);

//         // 選擇 2：不加油
//         backtrack(stations, fuelAfterDrive, numRefuel, newLoc, target);
//     }

//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         minStops = INT_MAX;
//         backtrack(stations, startFuel, 0, 0, target);
//         return (minStops == INT_MAX) ? -1 : minStops;
//     }
// };
