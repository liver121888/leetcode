class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long result = 0;
        priority_queue<int> pq;
        for (auto gift : gifts) {
            pq.push(gift);
        }
        
        while (k > 0) {
            int cur = pq.top();
            pq.pop();
            pq.push(sqrt(cur));            
            k--;
        }
        
        while (!pq.empty()) {
            int cur = pq.top();
            result += cur;
            pq.pop();
        }
        
        return result;
    }
};