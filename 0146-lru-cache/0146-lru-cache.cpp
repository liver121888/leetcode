class LRUCache {
public:

    // stores capacity
    int cap;
    // for O(1) access in get, put
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    // for keeping the limit
    list<pair<int, int>> lru;

    // Removing from arbitrary positions is one of the few things 
    // that a linked list does better than an array.

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // cout << "==get=="  << key << endl;
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;

        int value = it->second->second;
        lru.erase(it->second);
        lru.push_front({key, value});
        cache.erase(it);
        cache[key] = lru.begin();
        return value;
    }
    
    void put(int key, int value) {
        cout << "==put==" << endl;

        auto it = cache.find(key);
        if (it != cache.end()) {
            lru.erase(it->second);
            cache.erase(it);
        }

        lru.push_front({key, value});
        cache[key] = lru.begin();

        if (cache.size() > cap) {
            auto it = cache.find(lru.rbegin()->first);
            cache.erase(it);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // 