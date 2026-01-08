// I can use two stack to simulate a queue
// when push, push to first stack
// [1], [2]
// pop should be 1



class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {

        st1.push(x);
        
    }
    
    int pop() {

        while (!st1.empty()) {
            int data = st1.top();
            st1.pop();
            st2.push(data);
        }
        
        int result = st2.top();
        st2.pop();

        while (!st2.empty()) {
            int data = st2.top();
            st2.pop();
            st1.push(data);
        }

        return result;
        
    }
    
    int peek() {

        while (!st1.empty()) {
            int data = st1.top();
            st1.pop();
            st2.push(data);
        }
        
        int result = st2.top();

        while (!st2.empty()) {
            int data = st2.top();
            st2.pop();
            st1.push(data);
        }

        return result;

        
    }
    
    bool empty() {

        if (!st1.empty())
            return false;
        return true;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */