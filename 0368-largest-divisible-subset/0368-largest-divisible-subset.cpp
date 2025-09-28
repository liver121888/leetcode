class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        if (n == 0)
            return vector<int>();

        // Container to keep the largest divisible subset that ends with each of the nums
        // Let us define a function named EDS(X_i), which gives the largest divisible subset 
        // that ends with the number X_i

        auto EDS = vector<vector<int>>(n, vector<int>());

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            vector<int> maxSubset = vector<int>();
            for (int k = 0; k < i; ++k) {
                if (nums[i] % nums[k] == 0 && maxSubset.size() < EDS[k].size())
                    maxSubset = EDS[k];
            }

            // Extend the found subset with the element itself.
            EDS[i] = maxSubset;
            EDS[i].push_back(nums[i]);
        }

        // Find the largest of EDS values
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (ret.size() < EDS[i].size()) {
                ret = EDS[i];
            }
        }
        return ret;
    }
};