class Solution {
public:
    int maximum69Number (int num) {

        int num_bk = num;

        int lastSixPos = -1;
        int curPos = 0;
        while (num > 0) {
            if (num % 10 == 6)
                lastSixPos = curPos;
            // digits.push_front(num % 10);
            num /= 10;
            curPos += 1;
        }

        // for (auto digit : digits) {
        //     if digit
        // }


        // 9669

        return lastSixPos == -1 ? num_bk : (num_bk + 3 * pow(10, lastSixPos));

        
    }
};