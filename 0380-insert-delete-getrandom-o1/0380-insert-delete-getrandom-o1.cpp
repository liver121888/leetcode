class RandomizedSet {
public:

    // number, idx
    unordered_map<int, int> rMap;

    // idx, number
    vector<int> v;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if (rMap.find(val) == rMap.end()) {
            v.push_back(val);
            rMap.insert({val, v.size()-1});
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        
        if (rMap.find(val) != rMap.end()) {

            // 刪除技巧：swap with last
            // 太鬼了
            // 要刪 arr[idx]
            // 把最後一個元素搬到 idx
            // pop_back
            // 更新 map 裡那個被搬過來的元素的新位置

            // move first
            int idx = rMap.at(val);
            int temp = v[v.size()-1];
            swap(v[idx], v[v.size()-1]);
            rMap[temp]=idx;

            // then remove
            rMap.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {

        return v[rand() % v.size()];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */