// get O(1) key, value unorederd_map
// put in O(1), random access, linkedlist
// get -> update the recent used key, return value
// put -> update the recent used key, we might need to 
// remove least used key

// unorederd_map -> O(1) get()
// put -> X, priority_queue<time, key> minheap
// O(log(n))

// key, value
// list<pair<int,int>> l;
// most recent used in front, least in the back

// unorederd_map<key, ptr to the node> m;

// get
// query the map to get the ptr
// use ptr to get the value from the list
// if the key is not exsit in the map, we return -1;

// put function
// search in the map to see if we have the key
// Update or add key value

// update the list so lru can be correct
// check capacity
// remove lru key if necessary

// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// ["LRUCache","put","put","get","put","get","get"]
// [[2],[2,1],[1,1],[2],[4,1],[1],[2]]
// _, _, _, 1, _, -1, 1


class LRUCache {
public:

    int cap;
    // key, value
    list<pair<int,int>> l;

    // key, ptr
    unordered_map<int,list<pair<int,int>>::iterator> m;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

        auto it = m.find(key);

        if (it == m.end())
            return -1;

        // key, ptr
        // it

        int value = it->second->second;
        // cout << value << endl;
        
        // update the list
        l.erase(it->second);
        l.push_front({key, value});
        m[key] = l.begin();
        return value;
    }
    
    void put(int key, int value) {

        auto it = m.find(key);

        if (it != m.end()) {
            l.erase(it->second);
        } 

        l.push_front({key, value});
        m[key] = l.begin();

        // check capacity
        if (l.size() > cap) {
            // lru
            int lruKey = l.back().first;
            m.erase(lruKey);
            l.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */