class Solution {
public:

    int n;
    int ans = 0;


    void twoSumSortedVariation(const vector<int>& d, int i, int t) {

        int target = t - d[i];

        int l = i + 1;
        int r = n - 1; 
        
        // distinct index
        // distinct nubmer
        // we need to find in this range
        // any 2 of them the sum is <= target
        while (l < r) {
            int sum = d[l] + d[r];
            if (sum >= target) {
                r--;           
            } else if (sum < target) {
                // < target
                // every starts with l to r is one solution
                // we add them using r - l
                ans += (r-l);
                l++;
            }
        }
    }

    int threeSumSmaller(vector<int>& nums, int target) {

        n = nums.size();

        sort(nums.begin(), nums.end());

        // fix one number
        // traverse till the final triplet
        for (int i = 0; i < n - 2; i++) {
            twoSumSortedVariation(nums, i, target);
        }

        return ans;

    }


    // [0,-4,-1,1,-1,2]
    // -5
    // [-4,-1,-1,0,1,2]

    // -5





};