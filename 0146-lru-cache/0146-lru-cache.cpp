// class LRUCache {
// public:

//     // stores capacity
//     int cap;
//     // for O(1) access in get, put
//     unordered_map<int, list<pair<int, int>>::iterator> cache;
//     // for keeping the limit
//     list<pair<int, int>> lru;

//     // Removing from arbitrary positions is one of the few things 
//     // that a linked list does better than an array.
//     LRUCache(int capacity) {
//         cap = capacity;
//     }
    
//     int get(int key) {

//         // cout << "==get=="  << key << endl;
//         auto it = cache.find(key);

//         if (it == cache.end())
//             return -1;

//         int value = it->second->second;
//         lru.erase(it->second);
//         lru.push_front({key, value});
//         cache.erase(it);
//         cache[key] = lru.begin();
//         return value;
//     }
    
//     void put(int key, int value) {

//         // cout << "==put==" << endl;
//         auto it = cache.find(key);
//         if (it != cache.end()) {
//             lru.erase(it->second);
//             cache.erase(it);
//         }

//         lru.push_front({key, value});
//         cache[key] = lru.begin();

//         if (cache.size() > cap) {
//             auto it = cache.find(lru.rbegin()->first);
//             cache.erase(it);
//             lru.pop_back();
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Customized version
// Some requirements
// Store a key-value pair
// Update a key-value pair
// Given a key, determine if it exists in the data structure. If it does, return the value. If it doesn't, return -1.
// When a new key-value pair is added, create a new linked list node and put it at the back.
// When an existing key is updated or fetched, find its associated linked list node. Move it to the back.
// When a new key-value pair is added and the size of the data structure exceeds capacity, remove the linked list node at the front.

struct Node {
    int key, val;
    Node* next;
    Node* prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};


class LRUCache {

public:

    int capacity;
    unordered_map<int, Node*> dic;
    // we can use a queue but to remove a thing in a queue is O(n)
    // thus we use linked list, to maintain the sequence but O(1) operation
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (dic.find(key) == dic.end())
            return -1;
        
        Node* node = dic[key];
        // a key is used, we move the node to the back
        remove(node);
        add(node);
        return node->val;
        
    }
    
    void put(int key, int value) {
        // remove first if the node exist
        if (dic.find(key) != dic.end()) {
            Node *oldNode = dic[key];
            remove(oldNode);
        }

        // put the node in the back of the list
        Node *node = new Node(key, value);
        dic[key] = node;
        add(node);

        // keep the capacity
        if (dic.size() > capacity) {
            Node *nodeToDelete = head->next;
            remove(nodeToDelete);
            dic.erase(nodeToDelete->key);
        }
    }

    // append to the end
    void add(Node* node) {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

    // remove a node
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */