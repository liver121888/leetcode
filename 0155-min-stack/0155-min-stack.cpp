// get the minimum element in the stack
// we don't need to pop min, just retreive
// we can use a stack but keep a min, the problem is when we pop and if this is the min
// how can we find the next min fast

// we can first use a stack to solve the LIFO problem
// and what we pushed in can be a pair, that record the current smallest

// a stack: {-2, -2}, {0, -2}, {-3, -3}
// when we pop, just pop and then peek to update the min
// when we push, just peek then push
// when we get min, just get min

class MinStack {
public:

    stack<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {

        if (st.empty())
            st.push({val, val});
        else {
            st.push({val, min(val, st.top().second)});
        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }


    // st: {-2, -2}, {0, -2}, {-3, -3}


};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */