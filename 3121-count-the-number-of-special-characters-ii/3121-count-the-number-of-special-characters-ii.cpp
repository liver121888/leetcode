
// we can use a unordered_set to know if we met the char before
// we can also use vector to set bool since the range is within lowercase
// every lowercase occurrence of c appears before the first uppercase occurrence of c.
// record the upper case first appear index
// record the lower case last appear index
// comapre the two in the end
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lowerCaseIdx(26, -1);
        vector<int> upperCaseIdx(26, -1);

        for (int i = 0; i < word.size(); i++) {
            int charLowerCaseId = word[i] - 'a';
            int charUpperCaseId = word[i] - 'A';
            if (charLowerCaseId >= 0 && charLowerCaseId < 26) {
                lowerCaseIdx[charLowerCaseId] = i;
            } else {
                if (upperCaseIdx[charUpperCaseId] == -1)
                    upperCaseIdx[charUpperCaseId] = i;                
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (lowerCaseIdx[i] != -1 && upperCaseIdx[i] != -1 && 
                lowerCaseIdx[i] < upperCaseIdx[i])
                cnt++;
        }
        return cnt;
    }
};