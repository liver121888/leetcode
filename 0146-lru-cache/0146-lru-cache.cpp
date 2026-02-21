// get and put both in O(1) average time complexity
// capacity, need to query if the key exist
// update if the key exist, otherwise put the pair into the cache
// if after putting, exceed the the capacity, we remove the least recently used key
// get and put both involve using a key
// so we update the least recent used key

// need to have a queue structure, to find the least used key
// but when we try to update a key in the structure, we still need O(1) time complexity
// list data structure, unorederd_map<key, value>
// when we get the value, we can just access it 
// list of pair<key, value>, l, unordered_map<key, pointer to pair> m

// get -> m[key] -> ptr -> value;
// pointer delete it and insert it in the back
// update the list l, put this key to the back of the list -> most recent used key

// put -> we create a new pair and append to the list
// save the pointer and the key in the unordereed_map
// check the capacity, if over, envict

// O(1) -> hashmap for get
// O(1) -> put, we are not travering the list, we use the pointer

class LRUCache {
public:

    int capacity;
    // key, value
    list<pair<int, int>> cache;
    // ptr
    unordered_map<int, list<pair<int, int>>::iterator> table;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {

        auto it = table.find(key);

        if (it == table.end()) {
            return -1;
        }

        cout << key << endl;

        int val = it->second->second;
        cache.erase(it->second);

        
        // front: most recent used key
        cache.push_front({key,val});
        table[key] = cache.begin();
        return val;

    }
    
    void put(int key, int value) {

        auto it = table.find(key);

        // if exists, remove old node first
        if (it != table.end()) {
            cache.erase(it->second);
            table.erase(it);
        }

        // insert new to front
        cache.push_front({key, value});
        table[key] = cache.begin();

        // evict LRU if over capacity
        if (cache.size() > capacity) {
            int oldKey = cache.back().first;
            cache.pop_back();
            table.erase(oldKey);
        }
    }
};

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]
// list
// [_,_]

// map

// list
// [3, 3, 4, 4]

// map
// [[3, ptr3], [4, ptr4]]




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */