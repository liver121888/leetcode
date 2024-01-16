class RandomizedSet {
public:
    set<int> aSet;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (aSet.find(val) != aSet.end()) {
            return false;            
        } 
        aSet.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (aSet.find(val) != aSet.end()) {
            aSet.erase(val);
            return true;            
        }
        return false;
    }
    
    int getRandom() {
        int n = rand() % aSet.size();
        auto it = aSet.begin();
        while(n--){
            it++;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */