class Solution {
public:
    long long minimumSteps(string s) {
        // int zeroCnt = 0;
        int oneCnt = 0;
        
        long long result = 0;
        for (auto c : s) {
            
            if (c - '0' == 0) {
                
                result += oneCnt;
                // zeroCnt += 1;
            } else {
                // result += zeroCnt;
                oneCnt += 1;
            }    
        }
        
        return result;        
    }
};