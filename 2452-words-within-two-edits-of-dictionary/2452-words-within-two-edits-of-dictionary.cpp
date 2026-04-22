
// maximum two edits
// maybe we can build a trie
// and for each query we see if we can make it


// struct TrieNode {

//     vector<TrieNode*> children;
//     bool isEnd;

//     TrieNode() {
//         children.resize(26);
//         for (int i = 0; i < 26; i++)
//             children[i] = nullptr;
//         isEnd = false;
//     }

// };

// class Solution {
// public:


//     void insertTrie(TrieNode* root, string word) {

//         TrieNode* curr = root;

//         for (const auto& c : word) {
//             if (!curr->children[c - 'a']) {
//                 curr->children[c - 'a'] = new TrieNode();
//             }
//             curr = curr->children[c - 'a'];
//         }
//         curr->isEnd = true;
//     }


//     // queries = ["word","note","ants","wood"], 
//     // dictionary = ["wood","joke","moat"]
//     // word
//     // no r, c = r, i = 2
//     // subQuery d, diffCnt = 1
//     // we do have o
//     // under o, we see d
//     // thus return true
//     // we need to deal with diffCnt > 2

//     // "larapqqk"
//     // "iarapqqk"

//     // "iarapqqk"
//     // and it goes down to i so it's not working
//     // a l i s n
//     // we might need special handling when root?
//     // or what if we model it wrong?
//     // we don't need to check isEnd because they are the same length

//     bool queryTrie(TrieNode* node, string query, int i, int diffCnt) {

//         if (!node || diffCnt > 2)
//             return false;

//         if (i == query.size()) {
//             return node->isEnd && diffCnt <= 2;
//         }
        
//         // you got two options here
//         // directly match or don't match
//         for (int ch = 0; ch < 26; ch++) {
//             // we prune here so we not even 
//             // bother to go into the function
//             if (!node->children[ch])
//                 continue;

//             int newDiff = diffCnt + ((ch != (query[i] - 'a')) ? 1 : 0);
//             if (queryTrie(node->children[ch], query, i + 1, newDiff)) {
//                 return true;
//             }
//         }
//         return false;


//         // this greedy match will wrong because 
//         // dic "larapqqk", ...
//         // quey "iarapqqk"
//         // and it goes down to i so it's not working, because
//         // i might not be able to match
//         // a l i s n

//         // for (int i = 0; i < query.size(); i++) {
//         //     const auto& c = query[i];
//         //     if (!curr->children[c - 'a']) {
//         //         // skip the word and move on to next char
//         //         string subQuery = query.substr(i+1);
//         //         bool exist = false;
//         //         for (const auto& child : curr->children) {
//         //             exist = exist || queryTrie(child, subQuery, diffCnt+1);
//         //         }
//         //         return exist;
//         //     }
//         //     curr = curr->children[c - 'a'];
//         // }
//         // return true;
//     }

//     vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

//         vector<string> ans;

//         // some edge cases
//         if (queries.size() == 0 || dictionary.size() == 0) {
//             return ans;
//         }

//         // build trie
//         TrieNode* root = new TrieNode();
//         for (const auto& word : dictionary) {
//             insertTrie(root, word);
//         }

//         // query
//         for (const auto& query : queries) {
//             if (queryTrie(root, query, 0, 0)) {
//                 ans.push_back(query);
//             }
//         };        

//         return ans;
//     }
// };


// brute-force
class Solution {
public:
    bool helper(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for (const string& query : queries) {
            for (const string& word : dictionary) {
                if (helper(query, word)) {
                    ans.push_back(query);
                    break;
                }
            }
        }

        return ans;
    }
};
