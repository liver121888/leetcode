class Solution {
public:
    vector<int> sumZero(int n) {
        // n unique int that sums to zero
        // n = 5
        // [-7, -1, 1, 3, 4]
        // n = 3
        // [-1, 0, 1]
        // n = 1
        // [0]

        // n = 6
        // [-1, -3, 1, -2, 2, 3]

        // if n is odd -> we will include 0, and then move equal distance start from zero to the 2 sides of the numbers
        // if n is even, then we don't include 0, we just put postivie and negative numbers

        vector<int> ans;

        if (n % 2) {
            // if odd include 0
            ans.push_back(0);
        }

        for (int i = 1; i <= n/2; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }

        // n = 5
        // odd, n/2 = 2
        // ans = [0, 1, -1, 2, -2]

        // n = 6
        // [1, -1, -2, 2, -3, 3]

        // n = 3
        // [-1, 0, 1]
        // n = 1
        // [0]

        // 

        return ans;
        
    }
};