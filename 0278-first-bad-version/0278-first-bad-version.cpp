// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// we always call the api on the mid version
// it's either bad or good
// if it's bad, we serach left
// if it's good, we serach right
// we need to find the first occurance of bad
// the bad always exist

class Solution {
public:
    int firstBadVersion(int n) {
        // bad could be  2^31 - 1
        // 32 bit int -2^31 2^31-1
        // serach space is from 1 to n;
        int l = 1, r = n;
        while (l <= r) {
            
            int mid = l + (r - l)/2;
            if (isBadVersion(mid)) {
                // find left
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            // we want to find the first bad
            // l will be the ans
        }
        return l;


        // n = 5, bad = 4
        // l = 1, r = 5
        // mid = 3
        // good -> l = 4, r = 5
        // mid = 4 -> bad
        // r = 4 l = 4
        // mid = 4 -> bad
        // r = 3, loop stops

    }
};