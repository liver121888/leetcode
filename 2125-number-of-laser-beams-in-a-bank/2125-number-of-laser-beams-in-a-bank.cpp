class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastRowCnt = 0;
        int curRowCnt{};
        int ans = 0;
        for (auto row : bank) {
            curRowCnt = 0;
            for (auto c : row)
                if (c == '1')
                    curRowCnt++;
       
            // if (lastRowCnt == -1) {
            //     lastRowCnt = curRowCnt;
            //     continue;
            // }

            if(curRowCnt == 0)
                continue;

            ans += (lastRowCnt * curRowCnt);
            lastRowCnt = curRowCnt;
            
            
        }
        return ans;
    }
};