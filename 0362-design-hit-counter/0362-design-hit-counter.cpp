
// Several hits may happen at the same timestamp.
// past 5 minutes from timestamp (i.e., the past 300 seconds).

// timestamp is monotonically increasing).
// Follow up: What if the number of hits per second could be huge? 
// Does your design scale?

// invariant
// timestamp is always increasing
// we only need to track 300 in the past

// we can create a queue to save the timestamps
// q[1 2 3]
// get hits 4
// q.front = 1 is within 4 - 300
// return q.size

// q[1 2 3 300]
// get hit 300 -> within return q.size();

// get hit 301 -> out of bound
// envict
// keep checking and envict
// until we return q.size();

// n calls
// space: O(1), always 300
// time: O(1), we might need to envict 300

class HitCounter {
public:

    queue<int> q;

    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    // q [1 2 3 300]
    // getHITS 300 -> 4
    // q [1 2 3 300]
    // getHITS 301
    // t = 1


    int getHits(int timestamp) {
        int t = timestamp - 300;
        if (t < 0)
            t = 0;
        while (!q.empty() && q.front() <= t) {
            q.pop();
        }
        return q.size();        
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */