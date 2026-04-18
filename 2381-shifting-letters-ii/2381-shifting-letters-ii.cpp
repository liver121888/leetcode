class Solution {
public:

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int> diff(n);

        for (auto shift : shifts) {
            if (shift[2]) {
                diff[shift[0]]++;

                if (shift[1] + 1 < n) {
                    diff[shift[1] + 1]--;
                }

            } else {
                diff[shift[0]]--;

                if (shift[1] + 1 < n) {
                    diff[shift[1] + 1]++;
                }
            }
        }

        string result(n, ' ');
        int numOfShifts = 0;

        for (int i = 0; i < s.size(); i++) {
            numOfShifts = (numOfShifts + diff[i]) % 26;

            if (numOfShifts < 0)
                numOfShifts += 26;

            result[i] = 'a' + (s[i] - 'a' + numOfShifts) % 26;

        }

        return result;

    }
};