class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        // priority queue 
        // k smallets number
        // queue unitl k elements
        // iterate through the matrix, but keep queue to of size k
        // top priority queue, keep the new element

        // k = 8
        // [[1,5,9],[10,11,13],[12,13,15]]
        // maxQ [1 5 9 10 11 12 13 13]
        // 15 !< 13

        // matrix = [[-5]], k = 1

        // k = 4
        // [[1,5,9],[7,8,9],[5,6,7]]
        // [1 5 7 9] 8 -> [1 5 7 8]
        // [1 5 7 8] 5 - > [1 5 5 7]
        // [1 5 5 7] 6 - > [1 5 5 6]
        // 7 !< 6
        // return 6

        // row it's already sorted
        // compare the end points of the each row
        // [[1,5,9],
        //  [7,8,10],
        //  [8,9,11]]

        // k = 4, 1 + 2 + t + 2 + 1

        // this triangular sum = f(t) = t * (t-1) - t

        // t is the number that the sum didn't exceed k

        // if can find cloest number that didn't exceed k
        // the interested diagonal
        // check the diagonal maxQ of this size (k - already queued)
        // -> ans

        // to find t, we need O(k)

        // O(O(k) + O(n*log(k))) -> O(nlog(k))

        // find t
        // helper(k)
        // for (i to k)
        //   cal t * (t-1) - t
        //   if it exceed > 
        //     return t * (t-1) - t

        int n = matrix.size();
        priority_queue<int> maxQ;

        // O(n^2 * log(k))

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // if not of size k, queue in the element
                int curNumber = matrix[r][c];
                if (maxQ.size() < k) {
                    maxQ.push(curNumber);
                } else {
                    if (curNumber < maxQ.top()) {
                        maxQ.pop();
                        maxQ.push(curNumber);
                    }
                    // skip
                }
            }
        }

        // k >= 1
        // maxQ will always have a number
        return maxQ.top();
    }
};