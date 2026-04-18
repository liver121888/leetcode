
// after some operations
// we need to return the seats
// reservered on every flight
// we can go from query first to last and increase each 
// of them, that will require a lot of times
// instead we can have a sum array
// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
// Output: [10,55,45,25,25]


// what if we add reservations to the first flight in the range, 
// and remove them after the last flight in range? We can then 
// use the running sum to update reservations for all flights.

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int> res(n);
        for (const auto& v : bookings) {
            res[v[0] - 1] += v[2];
            if (v[1] < n) 
                res[v[1]] -= v[2];
        }

        for (auto i = 1; i < n; ++i)
            res[i] += res[i - 1];


        return res;
        
    }
};


