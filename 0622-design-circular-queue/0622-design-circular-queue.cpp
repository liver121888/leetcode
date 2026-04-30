
// You must solve the problem without using the built-in queue 
// data structure in your programming language. 

class MyCircularQueue {
public:

    vector<int> buffer;
    int head; // 队头索引（指向最老的元素）
    int tail; // 队尾索引（指向下一个空位）
    int count;
    int capacity;

    MyCircularQueue(int k): head(0), tail(0), count(0), capacity(k) {
        buffer.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        count++;
        return true;        
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        // 不需要清空数组，下次 enQueue 会自动覆盖
        // 例：head=1 → (1+1)%5 = 2
        head = (head + 1) % capacity;
        count--;

        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return buffer[head];  // head 直接指向最老的元素
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return buffer[(tail + capacity - 1) % capacity];  // tail prev one 直接指向最新的元素
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */