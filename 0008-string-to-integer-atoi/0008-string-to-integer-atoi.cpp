class Solution {
public:
    int myAtoi(string s) {
        int startReading = 0;
        long long ans = 0;
        bool isNegative = false;
        for (auto c : s) {   
            if ((c - '0' >= 0 && c - '0' <= 9) || c - '-' == 0 || c - '+' == 0  ) {
                if (c - '0' >= 0 && c - '0' <= 9) {
                    if (!isNegative) {
                        ans = 10 * ans + (c - '0');
                        if (ans > INT_MAX)
                            ans = INT_MAX;  
                    } else {
                        ans = 10 * ans - (c - '0');
                        if (ans < INT_MIN)
                            ans = INT_MIN;                        
                    }

                } else {
                    if (startReading == 0) {
                        if (c - '-' == 0)
                            isNegative = true;
                    } 
                    else
                        break;
                }
                if (startReading == 0)
                    startReading = 1;
                
            } else if (startReading || c - ' ' != 0)
                break;
            // leading spaces
            
        }

        //         if (isNegative)
        //             ans = -ans;

        //         if (ans > INT_MAX)
        //             ans = INT_MAX;

        //         if (ans = INT_MIN)
        //             ans = INT_MIN;

        return ans;        
    }
};