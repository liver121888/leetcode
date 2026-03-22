
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
// time: O(1), by amortization
// Hence in the worst case, a "single" call to the getHits 
// method can take O(n) time. However, we must notice 
// that each timestamp is processed only twice (first 
// while adding the timestamp in the queue in hit method 
// and second while removing the timestamp from the queue 
// in the getHits method). Hence if the total number of 
// timestamps encountered throughout is N, the overall time 
// taken by getHits method is O(N). This results in an amortized 
// time complexity of O(1) for a single call to getHits method.



// can use a deque to larger scale

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