
// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Return the minimum integer k such that she can eat all the bananas within h hours.
// choose a pile and eats k bananas


// Input: piles = [3,6,7,11], h = 8
// Output: 4
// 3 -> 11
// mid = 6

class Solution {
public:

    bool possible(const vector<int>& piles, int speed, int h) {
        long long timeTook = 0;
        for (const auto& pile : piles) {
            timeTook += pile/speed + (pile % speed == 0 ? 0 : 1);
        }
        return timeTook <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        if (n > h)
            return -1;

        // find the min in the piles
        // find the max in the piles
        // if we use the max in the piles as the speed
        // we can finish in n hours
        // if we use the min -> sum(celi(piles[i]/n))


        // the minimum integer k
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if (possible(piles, mid, h)) {
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }

        return l;





        
    }
};