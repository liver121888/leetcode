class Solution {
public:
    bool isValid(string word) {

        if (word.length() < 3)
            return false;

        auto vowels = unordered_set<char>({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});

        auto validChars = unordered_set<char>({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't','v', 'w', 'x', 'y', 'z',
                                            'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T','V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});

        auto consonants = unordered_set<char>({'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't','v', 'w', 'x', 'y', 'z',
                                            'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T','V', 'W', 'X', 'Y', 'Z'});


        bool hasAtLeastOneVowel = false;
        bool hasAtLeastOneConsonant = false;

        for (auto c : word) {
            if (vowels.find(c) != vowels.end()) {
                hasAtLeastOneVowel = true;
            }

            if (consonants.find(c) != consonants.end()) {
                hasAtLeastOneConsonant = true;
            }

            if (validChars.find(c) == validChars.end())
                return false;

        }
        return hasAtLeastOneVowel && hasAtLeastOneConsonant;
    }
};