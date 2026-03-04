// Up to R links to its children, with each link corresponding to one of R possible character values. 
// In this article, we assume R=26 for lowercase Latin letters.
// Trie (Prefix Tree)
// R = 26 (lowercase 'a'..'z')
// 每個節點有最多 26 個 child pointer，並用 isEnd 表示「是否有單字在此結束」
// 這版固定 26 指標的 tradeoff？
// 快（O(1) child lookup）但空間大；如果字元集合更大/更稀疏，會考慮用 unordered_map<char, TrieNode*> 省空間。
class TrieNode {
private:
    TrieNode* links[26]; // links[i] = 指向下一層字母 (char)('a'+i) 的子節點
    bool isEnd;          // true 表示有單字在這個節點結束（完整單字）

public:
    TrieNode() : isEnd(false) {
        // 初始化：全部 child pointer = nullptr
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }

    // O(1): 查某字母 child 是否存在
    bool containsKey(char ch) const {
        return links[ch - 'a'] != nullptr;
    }

    // O(1): 取得某字母 child（可能為 nullptr）
    TrieNode* get(char ch) const {
        return links[ch - 'a'];
    }

    // O(1): 設定某字母 child
    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    // O(1): 標記「這裡是某個單字的結尾」
    void setEnd() {
        isEnd = true;
    }

    // O(1): 是否為單字結尾
    bool isEndOfWord() const {
        return isEnd;
    }

    // helper: 給 destructor 遞迴釋放時用
    TrieNode* childAt(int i) const { return links[i]; }
};

class Trie {
private:
    TrieNode* root;

    // searchPrefix(word)
    // 功能：從 root 沿著 word 的字母一路往下走
    // - 如果途中某個字母不存在，回傳 nullptr（表示 prefix 不存在）
    // - 否則回傳走到最後那個節點
    //
    // 時間複雜度：O(L)
    //   L = word 長度，每個字母做 O(1) child 查詢/跳轉
    //
    // 空間複雜度：O(1) 額外（只用到指標 node）
    TrieNode* searchPrefix(const string& word) const {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) return nullptr;
            node = node->get(c);
        }
        return node;
    }

    // freeNode(node)
    // 功能：後序遍歷遞迴 delete 整棵 Trie
    //
    // 時間複雜度：O(N * R)（嚴格）/ O(N)（常用說法）
    //   N = Trie 裡總節點數
    //   每個節點都會被拜訪一次，且會掃 26 個 child
    //   因為 R=26 是常數，所以通常寫 O(N)
    //
    // 空間複雜度：O(H)（遞迴 call stack）
    //   H = Trie 高度（最長單字長度）
    void freeNode(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            freeNode(node->childAt(i));
        }
        delete node;
    }

public:
    // 建構：建立 root
    // 時間 O(1)，空間 O(1)
    Trie() {
        root = new TrieNode();
    }

    // insert(word)
    // 逐字建立路徑：
    // - 若 child 不存在 -> new TrieNode()
    // - 最後節點 setEnd()
    //
    // 時間複雜度：O(L)
    // 空間複雜度：
    // - 最好：O(1)（路徑都已存在）
    // - 最壞：O(L) 新增 L 個節點（每個字母都沒出現過）
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->containsKey(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    // search(word)
    // 先走 prefix：
    // - 若路徑不存在 -> false
    // - 路徑存在還不夠，必須 isEnd=true 才算完整單字
    //
    // 時間複雜度：O(L)
    // 空間複雜度：O(1) 額外
    bool search(const string& word) const {
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEndOfWord();
    }

    // startsWith(prefix)
    // 只要 prefix 路徑存在就回 true（不需要 isEnd）
    //
    // 時間複雜度：O(L)
    // 空間複雜度：O(1) 額外
    bool startsWith(const string& prefix) const {
        return searchPrefix(prefix) != nullptr;
    }

    // Destructor: 釋放整棵 Trie
    // 時間複雜度：O(N)（R=26 常數）
    // 空間複雜度：O(H) 遞迴深度
    ~Trie() {
        freeNode(root);
        root = nullptr;
    }
};

/*
總結複雜度（對 LeetCode 最常用的寫法）：
- insert(word):   O(L)
- search(word):   O(L)
- startsWith(pre):O(L)
- 空間：O(N * R) pointers（每節點 26 個指標） + O(N) nodes
  其中 N = Trie 節點總數（約等於所有插入字串的「不重複前綴」數量）
*/

/**
 * Usage:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 * delete obj;
 */




// 盜版
// class Trie {
// public:
    
//     unordered_map<string, bool> db;
    
//     // create a hash table and put in all the words in it
//     Trie() {
        
//     }
    
//     void insert(string word) {

//         db[word] = true;
//         string s = "";
//         int n = word.length();
//         for (int i = 0; i < n - 1; i++) {
//             s += word[i];
//             if (db.find(s) == db.end())
//                 db[s] = false;
//         }

//     }
    
//     bool search(string word) {        
//         if (db.find(word) != db.end()) {
//             return db[word];
//         }
//         return false;
//     }
    
//     bool startsWith(string prefix) {
//         return db.find(prefix) == db.end() ? false : true;        
//     }
// };

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */