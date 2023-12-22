class Solution {
public:
    int maxScore(string s) {
        int maxScore = -INT_MAX;
        int score = 0;
        int numZero = 0;
        int numZeroAtMax = 0;
        int numOne = 0;
        int numOneAtMax = 0;


        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' == 0) {
                score++;
                numZero++;
            } else {
                score--;
                numOne++;
            }
            if (score > maxScore && i != s.size() - 1) {
                maxScore = score;
                numZeroAtMax = numZero;
                numOneAtMax = numOne;
            }
        }
        
        return numZeroAtMax + (numOne - numOneAtMax);
        
    }
};