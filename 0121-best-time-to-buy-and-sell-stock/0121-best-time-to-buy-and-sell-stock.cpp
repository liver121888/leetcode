class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // min must before the max
        // from the back we find max
        // from the font we find min and cal the different

        // curMaX and curMin
        int maxProfit = 0; int curMin = INT_MAX;
        for (auto price : prices) {
            if (price < curMin)
                curMin = price;
            else if (price - curMin > maxProfit)
                maxProfit = price - curMin;
        }
        return maxProfit;
    }
};