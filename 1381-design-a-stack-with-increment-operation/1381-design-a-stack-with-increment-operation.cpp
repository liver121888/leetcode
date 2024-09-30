class CustomStack {
public:
    
    vector<int> storage;
    int storageSize = 0;
    int maxSize = 0;
    
    CustomStack(int maxSize) {
        storage = vector<int>();
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (storageSize < maxSize) {
            storage.push_back(x);
            storageSize += 1;
        }
        
    }
    
    int pop() {
        if (storageSize == 0)
            return -1;
        else {
            int tmp = storage.back();
            storage.pop_back();
            storageSize -= 1;
            return tmp;
        }
        
    }
    
    void increment(int k, int val) {
        
        if (storageSize < k) {
            for (int i = 0; i < storageSize; i++) {
                storage[i] += val;
            }           
        } else {
            for (int i = 0; i < k; i++) {
                storage[i] += val;
            } 
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */