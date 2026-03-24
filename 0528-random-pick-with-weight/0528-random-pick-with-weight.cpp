// Random Pick with Weight
// have the sum of w
// pick the index according to their probability
// n entry for w
// how can we pick numbers according to there weight?
// rand() -> 0 ~ RAND_MAX
// we can store how many times a number to reflect the 
// probavility

class Solution {
public:

    vector<int> prefixSums;

    Solution(vector<int>& w) {
        for (const auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }
    
    int pickIndex() {
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums[prefixSums.size()-1];

        // run a linear search to find the target zone
        // for (int i = 0; i < prefixSums.size(); ++i)
        //     if (target < prefixSums[i])
        //         return i;

        // [1 2 3 4 5]
        // [1 3 6 10 15]
        // 14
        // 10 15
        // 14
        // return upperBound

        // run binary search
        int l = 0, r = prefixSums.size()-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (prefixSums[mid] < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return l == prefixSums.size() ? prefixSums.size() - 1 : l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */