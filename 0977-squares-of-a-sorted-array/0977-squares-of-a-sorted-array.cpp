
// non-decreasing order
// we can square each of them and sort
// O(nlogn)
// we can find the zero and square from the middle
// and arrange them

// an O(n) solution using a different approach?

class Solution {
public:


    // find the first occurance that a number > 0

    vector<int> sortedSquares(vector<int>& nums) {

        // last non-positive
        // auto it = upperbound(nums.begin(), nums.end(), 0);
        // int idx = it - nums.begin();

        // we don't need to do the above
        // we do two pointers
        // l -> the most negative
        // r -> the most positive, input position

        int n = nums.size();
        vector<int> ans(n, -1);

        int l = 0, r = n - 1, idx = n - 1;
        while (l <= r) {
            
            int lSquare = nums[l] * nums[l];
            int rSquare = nums[r] * nums[r];

            if (lSquare > rSquare) {
                l++;
            } else {
                r--;
            }

            ans[idx] = max(lSquare, rSquare);
            idx--;
        }

        // [-4,-1,0,3,10]

        // 100 


        return ans;
    }
};