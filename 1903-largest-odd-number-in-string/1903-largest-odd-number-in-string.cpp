class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int right = 0;

        for (right = n - 1; right >= 0; right--) {
            if ((num[right] - '0') % 2 != 0)
                break;
        }
                
        return num.substr(0, right - 0 + 1);
    }
};