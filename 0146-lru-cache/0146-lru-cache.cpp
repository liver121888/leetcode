


// we can use a linkedlist and an unordered_map to save the pair
// If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// least recent used put in the back -> we can just pop
// most recent used put in the front -> we keep pushing
// if use -> we move the pair to the front

class LRUCache {
public:

    // key, value
    list<pair<int,int>> cache;
    // key -> iterator
    unordered_map<int, list<pair<int,int>>::iterator> key2iter;

    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    // check if the key exists
    // true -> return the value
    // modify the cache move the key to most recent
    // used key
    // modify the map to update the iter
    // false -> return -1;
    int get(int key) {
        auto iter = key2iter.find(key);
        if (iter == key2iter.end())
            return -1;
        int value = iter->second->second;
        // remove是O(n)掃一遍
        // cache.remove({key,value});

        // 直接用 erase 才是O(1)
        cache.erase(iter->second);

        // most recent used
        cache.push_front({key, value});
        // front returns an element
        // key2iter[key] = cache.front();
        // begin returns iterator
        key2iter[key] = cache.begin();
        return value;
    }       
    
    // check if the key exists
    // modify the cache move the key to most recent
    // used key
    // modify the map to update the iter

    // check the size if the size is larger
    // we envict the pair from the list
    // also erase in the map

    void put(int key, int value) {

        auto iter = key2iter.find(key);
        if (key2iter.find(key) != key2iter.end()) {
            // first need to remove if exist
            cache.erase(iter->second);
        }
        cache.push_front({key, value});
        key2iter[key] = cache.begin();

        if (cache.size() > n) {
            // envict least recent used
            const auto [k, v] = cache.back();
            cache.pop_back();
            key2iter.erase(k);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */