
// Check if the reverse of word is present. 
// If it is, then we have a case 1 pair by appending the reverse onto the end of word.
// For each suffix of word, check if the suffix is a palindrome. if it is a palindrome, 
// then reverse the remaining prefix and check if it's in the list. 
// If it is, then this is an example of case 2.
// For each prefix of word, check if the prefix is a palindrome. if it is a palindrome, 
// then reverse the remaining suffix and check if it's in the list. If it is, 
// then this is an example of case 3.

// TLE
// class Solution {
// public:

//     bool isPalindromeBetween(string word, int front, int back) {
//         while (front < back) {
//             if (word[front] != word[back])
//                 return false;
//             front++;
//             back--;
//         }
//         return true;
//     }

//     vector<string> allValidPrefixes(string word) {
//         vector<string> validPrefixes;
//         for (int i = 0; i < word.length(); i++) {
//             if (isPalindromeBetween(word, i, word.length() - 1))
//                 validPrefixes.push_back(word.substr(0, i));
//         }
//         return validPrefixes;
//     }

//     vector<string> allValidSuffixes(string word) {
//         vector<string> validSuffixes;
//         for (int i = 0; i < word.length(); i++) {
//             if (isPalindromeBetween(word, 0, i))
//                 validSuffixes.push_back(word.substr(i+1));
//         }
//         return validSuffixes;
//     }

//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         // Build a word -> original index mapping for efficient lookup.
//         unordered_map<string, int> wordSet;
//         for (int i = 0; i < words.size(); i++) {
//             wordSet[words[i]] = i;
//         }
//         vector<vector<int>> solution;

//         for (const auto& [word, currentWordIndex] : wordSet) {
//             string reverseWord = word;
//             reverse(reverseWord.begin(), reverseWord.end());

//             // Build solutions of case #1. This word will be word 1.
//             if (wordSet.find(reverseWord) != wordSet.end() && wordSet[reverseWord] != currentWordIndex) {
//                 solution.push_back({currentWordIndex, wordSet[reverseWord]});
//             }

//             // Build solutions of case #2. This word will be word 2.
//             for (string suffix : allValidSuffixes(word)) {
//                 reverse(suffix.begin(), suffix.end());
//                 if (wordSet.find(suffix) != wordSet.end()) {
//                     solution.push_back({wordSet[suffix], currentWordIndex});
//                 }
//             }

//             // Build solutions of case #3. This word will be word 1.
//             for (string prefix : allValidPrefixes(word)) {
//                 reverse(prefix.begin(), prefix.end());
//                 if (wordSet.find(prefix) != wordSet.end()) {
//                     solution.push_back({currentWordIndex, wordSet[prefix]});
//                 }
//             }
//         }

//         return solution;
//     }
// };


// Approach 3: Using a Trie
// put the word in reverse to the trie
// so when we encounter a word, if the word exist
// we know the reverse of the word exist
class TrieNode {
public:
    int wordEnding = -1;  // -1 means no word ends here
    unordered_map<char, TrieNode*> next;
    vector<int> palindromePrefixRemaining;
};

class Solution {
public:
    // Check whether s[i ... end] is palindrome
    bool hasPalindromeRemaining(const string& s, int i) {
        int p1 = i;
        int p2 = s.size() - 1;

        while (p1 < p2) {
            if (s[p1] != s[p2]) return false;
            p1++;
            p2--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* trie = new TrieNode();

        // Build the Trie with reversed words
        for (int wordId = 0; wordId < words.size(); wordId++) {
            string word = words[wordId];
            string reversedWord(word.rbegin(), word.rend());

            TrieNode* currentTrieLevel = trie;

            for (int j = 0; j < word.size(); j++) {
                if (hasPalindromeRemaining(reversedWord, j)) {
                    currentTrieLevel->palindromePrefixRemaining.push_back(wordId);
                }

                char c = reversedWord[j];

                if (currentTrieLevel->next.find(c) == currentTrieLevel->next.end()) {
                    currentTrieLevel->next[c] = new TrieNode();
                }

                currentTrieLevel = currentTrieLevel->next[c];
            }

            currentTrieLevel->wordEnding = wordId;
        }

        // Find pairs
        vector<vector<int>> pairs;

        for (int wordId = 0; wordId < words.size(); wordId++) {
            string word = words[wordId];

            TrieNode* currentTrieLevel = trie;

            for (int j = 0; j < word.size(); j++) {
                // Case 3:
                // current trie node is already a full word,
                // and the remaining part of current word is palindrome.
                if (currentTrieLevel->wordEnding != -1 &&
                    hasPalindromeRemaining(word, j)) {
                    pairs.push_back({wordId, currentTrieLevel->wordEnding});
                }

                char c = word[j];

                if (currentTrieLevel->next.find(c) == currentTrieLevel->next.end()) {
                    currentTrieLevel = nullptr;
                    break;
                }

                currentTrieLevel = currentTrieLevel->next[c];
            }

            if (currentTrieLevel == nullptr) continue;

            // Case 1:
            // current word exactly matches a reversed word in trie.
            if (currentTrieLevel->wordEnding != -1 &&
                currentTrieLevel->wordEnding != wordId) {
                pairs.push_back({wordId, currentTrieLevel->wordEnding});
            }

            // Case 2:
            // current word is shorter, and the remaining part of another word is palindrome.
            for (int other : currentTrieLevel->palindromePrefixRemaining) {
                pairs.push_back({wordId, other});
            }
        }

        return pairs;
    }
};