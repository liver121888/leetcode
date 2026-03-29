

// 這不是「超過容量就丟掉元素」的 queue，而是「滿了就阻塞 producer」的 queue。
// 但題目要的是：
// 如果滿了，enqueue 的 thread 要卡住等
// 如果空了，dequeue 的 thread 要卡住等

#include <mutex>
#include <condition_variable>

using namespace std;

class BoundedBlockingQueue {
private:
    queue<int> q;
    mutex mtx;
    int cap;
    condition_variable not_full;
    condition_variable not_empty;

public:
    BoundedBlockingQueue(int capacity) {
        cap = capacity;
    }
    
    void enqueue(int element) {

        unique_lock<mutex> lock(mtx);

        not_full.wait(lock, [this](){ return q.size() < cap; });

        q.push(element);
        not_empty.notify_one();    
    }
    
    int dequeue() {

        unique_lock<mutex> lock(mtx);

        not_empty.wait(lock, [this](){ return !q.empty(); });
        int temp = q.front();
        q.pop();
        not_full.notify_one();
        
        return temp;

    }
    
    int size() {

        lock_guard<mutex> lock(mtx);
        return q.size();
        
    }
};