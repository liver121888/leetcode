class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        vector<int> remainderOne;
        vector<int> remainderTwo;

        int wholeSum = 0;
        for (auto num : nums) {
            wholeSum += num;
            if (num % 3 == 1)
                remainderOne.push_back(num);
            else if (num % 3 == 2)
                remainderTwo.push_back(num);
            // else does nothing
        }

        sort(remainderOne.begin(), remainderOne.end(), greater<int>());
        sort(remainderTwo.begin(), remainderTwo.end(), greater<int>());


        // [2,6,2,2,7]
        // wholeSum = 19
        // remainderOne 7
        // remainderTwo 2 2 2

        int n1 = remainderOne.size(); 
        int n2 = remainderTwo.size();

        int remove = INT_MAX;
        if (wholeSum % 3 == 0) {
            return wholeSum;
        } else if (wholeSum % 3 == 1) {
            if (!remainderOne.empty())
                remove = min(remove, remainderOne[n1-1]);
            if (remainderTwo.size() >= 2)
                remove = min(remove, remainderTwo[n2-1] + remainderTwo[n2-2]);
        } else {
            if (!remainderTwo.empty())
                remove = min(remove, remainderTwo[n2-1]);
            if (remainderOne.size() >= 2)
                remove = min(remove, remainderOne[n1-1] + remainderOne[n1-2]);
        }
        return wholeSum-remove;
    }
};