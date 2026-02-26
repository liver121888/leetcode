

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// Output: 5

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0

// if the endword is not in the wordlist
// return 0

// "1" "-"
// lowercase character

// hot <-> dot build a edge

// multiple ways to start the bfs "hit"
// wordList = ["hot","hic", "dot","dog","lot","log","cog"]
// for the valid start position, we bfs and see if we can find the target word
// wordList is of size n
// time: O(n) we marked visited, visit a node one time
// space: O(n^2)

// hot, we need to quickly find all the word that it can transition to
// hot [dot hic]
// how can we do this efficiently
// hot -> *ot, h*t, ho*
// dot -> *ot, d*t, do*
// hic -> *ic, h*c, hi*

// *ot, {hot, dot}, h*t
// we traverse this map to build edges between the words


class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int strLen = wordList[0].length();
        // key, e.g. *ot, h*t, value is the index
        unordered_map<string, vector<string>> groups;
        bool hasSolution = false;
        for (int i = 0; i < wordList.size(); i++) {
            string word = wordList[i];
            if (word == endWord)
                hasSolution = true;
            for (int j = 0; j < strLen; j++) {
                // substr自動取到結尾
                string key = word.substr(0, j) + '*' + word.substr(j+1);
                groups[key].push_back(word);
            }
        }
        if (!hasSolution)
            return 0;

        // Queue for BFS
        queue<pair<string, int>> Q;
        Q.push(make_pair(beginWord, 1));
        unordered_map<string, bool> visited;
        visited[beginWord] = true;
        while (!Q.empty()) {
            pair<string, int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < strLen; i++) {
                // Intermediate words for current word
                string key = word.substr(0, i) + '*' + word.substr(i + 1);
                // Next states are all the words which share the same
                // intermediate state.
                for (string adjacentWord : groups[key]) {
                    // If at any point if we find what we are looking for
                    // i.e. the end word - we can return with the answer.
                    if (adjacentWord == endWord) {
                        return level + 1;
                    }
                    // Otherwise, add it to the BFS Queue. Also mark it visited
                    if (!visited[adjacentWord]) {
                        visited[adjacentWord] = true;
                        Q.push(make_pair(adjacentWord, level + 1));
                    }
                }


            }

        }



        return 0;
        
    }
};