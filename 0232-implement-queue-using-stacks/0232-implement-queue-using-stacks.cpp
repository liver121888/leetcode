// I can use two stack to simulate a queue
// when push, push to first stack
// [1], [2]. [3]
// pop should be 1

// 1
// 2

// 1
// 2

// 1
// 2
// 3


class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;

    int front;

    MyQueue() {
        
    }
    
    // O(n)
    // void push(int x) {

    //     if (s1.empty())
    //         front = x;

    //     while (!s1.empty()) {
    //         s2.push(s1.top());
    //         s1.pop();
    //     }
    //     s2.push(x);
    //     while (!s2.empty()) {
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
        
    // }
    
    // // O(1)
    // int pop() {

    //     int res = s1.top();
    //     s1.pop();
    //     if (!s1.empty())
    //         front = s1.top();
    //     return res;
        
    // }
    
    // // O(1)    
    // int peek() {

    //     return front;
        
    // }
    
    // // O(1)
    // bool empty() {

    //     return s1.empty();
        
    // }


    void push(int x) {
        if (s1.empty())
            front = x;
        s1.push(x);
    }

   int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
    }

    // Return whether the queue is empty.
    bool empty() {
        return s1.empty() && s2.empty();
    }

    // Get the front element.
    int peek() {
        if (!s2.empty()) {
            return s2.top();
        }
        return front;
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