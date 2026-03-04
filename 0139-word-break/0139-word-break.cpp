// u can build a trie out of it
//
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

// build an unordered_set of wordDict

// for each position, we can backtrack
// the option is end at current and see if it's possible
// or don't end and keep going
// max(O(2^n), O(k))

// we can keep the bool in the dp, to indicate if it's possible to build 
// let s.length() = n
// wordDict.size() = m
// k is the word in wordDict size
// dp[n-1] = (dp[1] && dp[n-2]

// dp(i)=any(s[i - word.length + 1, i]==word && dp(i - word.length))
// That is, there exists any word that satisfies both of the listed conditions.

class Solution {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false), children(unordered_map<char, TrieNode*>()) {}
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (const string& word  : wordDict) {
            TrieNode* curr = root;
            for (const auto& c : word) {
                if (curr->children.find(c) == curr->children.end()) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->isWord = true;
        }

        vector<bool> dp(s.length());
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode* curr = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if (curr->children.find(c) == curr->children.end()) {
                        // No words exist
                        break;
                    }

                    curr = curr->children[c];
                    if (curr->isWord) {
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
};

// dp solution top down
// Time complexity: O(n⋅m⋅k)
// There are n states of dp(i). Because of memoization, we only calculate each state once. 
// To calculate a state, we iterate over m words, and for each word perform some substring operations which costs O(k). 
// Therefore, calculating a state costs O(m⋅k), and we need to calculate O(n) states.

// Space complexity: O(n)
// The data structure we use for memoization and the recursion call stack can use up to O(n) space.

// class Solution {
// public:

//     vector<int> memo;
//     vector<string> wordDict;
//     string s;

//     bool dp(int i) {
//         if (i < 0) return true;

//         if (memo[i] != -1) {
//             return memo[i] == 1;
//         }

//         for (string word : wordDict) {
//             int currSize = word.length();
//             // Handle out of bounds case
//             if (i - currSize + 1 < 0) {
//                 continue;
//             }

//             if (s.substr(i - currSize + 1, currSize) == word &&
//                 dp(i - currSize)) {
//                 memo[i] = 1;
//                 return true;
//             }
//         }

//         memo[i] = 0;
//         return false;
//     }


//     bool wordBreak(string s, vector<string>& wordDict) {
//         memo = vector(s.length(), -1);
//         this->wordDict = wordDict;
//         this->s = s;
//         return dp(s.length() - 1);
//     }
// };

