class Trie {
public:
    
    unordered_map<string, bool> db;
    
    // create a hash table and put in all the words in it
    Trie() {
        
    }
    
    void insert(string word) {

        db[word] = true;
        string s = "";
        int n = word.length();
        for (int i = 0; i < n - 1; i++) {
            s += word[i];
            if (db.find(s) == db.end())
                db[s] = false;
        }

    }
    
    bool search(string word) {        
        if (db.find(word) != db.end()) {
            return db[word];
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        return db.find(prefix) == db.end() ? false : true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */