class Solution {
public:
    bool doesAliceWin(string s) {
        
        // Bob can remove zero vowel substring

        // apple -> 2 vowels
        // leetcoder -> 4 vowels
        // can we conclude that if even number of vowel alice will win?
        // no, if zero vowel alice lose
        // if s = "aa" -> alice take one, bob 

        // bbcd

        // if odd number of vowel
        // abcccddea -> alice wins

        // do we have to remove the substring from the begining?

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int numVowels = 0;
        for (auto c : s) {
            if (vowels.find(c) != vowels.end()) {
                numVowels++;
            }
        }
        cout << numVowels << endl;
        if (numVowels == 0)
            return false;

        return true;

    }
};