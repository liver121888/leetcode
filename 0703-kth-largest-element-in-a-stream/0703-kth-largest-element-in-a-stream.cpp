class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> data;
    int kth{};
    KthLargest(int k, vector<int>& nums) { 
        kth = k;
        
        for (auto num : nums) {
            add(num);
        }
            
    }
    
    int add(int val) {
        if (data.size() < kth || data.top() < val) {
            data.push(val);
            if (data.size() > kth) {
                data.pop();
            }
            
        }

        return data.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */