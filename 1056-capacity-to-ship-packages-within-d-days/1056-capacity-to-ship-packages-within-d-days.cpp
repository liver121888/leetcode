class Solution {
public:

    int simulate(const vector<int>& weights, int cap) {
        // return days
        int ans = 0;
        int i = 0; int currDayW = 0;
        while (i < weights.size()) {
            if (currDayW + weights[i] <= cap)
                currDayW += weights[i];
            else {
                ans++;
                currDayW = weights[i];
            }
            i++;
        }
        // last day
        return ans + 1;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // minimum capacity to satisfy the days constraint
        // weights, we need to ship these cargo in order

        // one easy obs: ans > max_element(weights)

        // brute-force
        // max_element(weights) -> simulate -> until we satisfy the days constraint
        // 1 day -> sum(weights) = capacity

        // search space: from max_element ~ sum of size m
        // binary search to search for this ans O(log(m)), simulate O(n)
        // O(log(m) * n)

        // space O(1)

        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        // [1,2,3,1,1], days = 4
        // l = 3
        // r = 8
        // mid 5
        // d = 2

        // r = 4

        // l = 3
        // r = 4
        // mid 3
        // 3 days
        // l = 3
        // r = 2

        // upper_bound problem
        // finding the max element that <= days


        // binary search to search the solution
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int d = simulate(weights, mid);
            if (d > days) {
                // increase capacity
                l = mid + 1;
            } else if (d <= days) {
                // too large a capacity to ship cargo
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;        
    }
};