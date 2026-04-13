
// a naive way is to use unorder_map
// if it's .., 

// looks like a trie question
// word in addWord consists of lowercase English letters.

struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode() {
        children.resize(26);
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }

        // mark as a word
        curr->isEnd = true;
        
    }

    bool searchInNode(string word, TrieNode* node) {

        TrieNode* curr = node;
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            // can match any char
            if (ch == '.') { 
                for (const auto& child : curr->children) {
                    if (child) {
                        if (searchInNode(word.substr(i+1), child))
                            return true;
                    }
                }
                return false;
            } else {
                if (!curr->children[ch - 'a']) {
                    return false;
                } else {
                    curr = curr->children[ch - 'a'];
                }
            }
        }
        // check if isEnd
        return curr->isEnd;
    }
    
    bool search(string word) {

        // if it's b.. , we don't know which route to go down
        // we just want to know if there is a word that ends
        // with len 3
        // a naive way to keep trying every words and see if there
        // is a one word
        // thinking it as recursive
        // so you will want to create this recursion function
        return searchInNode(word, root);         
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */