

// test case1
// [5 7 5 7 4 5]
// 5 -> freq 3
// 7 -> freq 2
// 4 -> 1

// test case2
// [5 7 5 7 4 4 5]
// 5 -> freq 3
// 4 -> freq 2 and more recently pushed
// 7 -> freq 2

// freq
// time it's being pushed

// pq
// 1,5
// 1,7

// unordered_map to store 5 -> if not the smae we remove 
// 2,5
// 1,5
// 1,7


// [5,7,5,7,4]

// [5,7,5,4]

// unordered_map number -> latest pushed in iterator
// pq ()


class FreqStack {
public:

    unordered_map<int, int> val2freq;
    unordered_map<int, vector<int>> freq2val;
    int maxFreq = 0;

    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int f = ++val2freq[val];
        freq2val[f].push_back(val);
        maxFreq = max(maxFreq, f);
    }
    
    int pop() {
        int val = freq2val[maxFreq].back();
        freq2val[maxFreq].pop_back();
        
        val2freq[val]--;
        
        if (freq2val[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */