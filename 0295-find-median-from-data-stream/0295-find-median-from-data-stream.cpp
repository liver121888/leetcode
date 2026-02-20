// There are two cases
// if the size is even: (size()/2 + size()/2-1)/2
// if the size is odd: size()/2
// problem is that we need to keep updating the data
// we also need to keep sorting the data
// we can have a brute force method
// vector, sort every time
// either add O(nlogn), or add O(nlogn)

// what if we have one maxHeap and one minHeap
// insert to maxHeap first
// if coming number is larger, put it in the min Heap
// and compare the top amd put in the element by turns
// so two heaps are roughly the same size
// when query, we choose either maxHeap or minHeap 
// no what if we alwyas put in the maxHeap?
// so we need a balance mechanism
// to keep the maxHeap and minHeap roughly same size

// we maintain linked list in sorted manner
// O(n) add
// O(n) find median, just traverse

// two heap method
// time: O(logn)
// space: O(n)

// two heap method
class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {

    }
    
    // max-heap lo is allowed to store, at worst, one more element more than the min-heap
    void addNum(int num) {

        maxHeap.push(num);
        minHeap.push(maxHeap.top());

        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        // lo.size > hi.size() means that it is odd size
        return maxHeap.size() > minHeap.size() ? maxHeap.top() :
            ((double) maxHeap.top() + minHeap.top()) * 0.5;
    }
};

// vector method
// class MedianFinder {
// public:

//     vector<int> store; // resize-able container

//     MedianFinder() {

//     }
    
//     void addNum(int num) {

//         if (store.empty())
//             store.push_back(num);
//         else
//             // find the first occurance of num
//             store.insert(lower_bound(store.begin(), store.end(), num), num);

//     }
    
//     double findMedian() {
//         int n = store.size();
//         return n % 2 ? store[n / 2] : ((double) store[n / 2 - 1] + store[n / 2]) * 0.5;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */