

// the k most frequent strings that shows in the words
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// i: 2
// love: 2
// we output i first because it has lexicographical lower

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// ["the","is","sunny","day"]
// 4, 3, 2 and 1 respectively.

// we can have a counter
// unoerderd_map<string, int> 
// but it cannot see which is most frequent

// heap
// K largest frequency number that appeared
// 4 3 2 1 1 1 1 1 -> 4 3 2 1 

// 4,

// brute-force
// the 4:
// "is: 3
// "sunny" : 2
// ,"day" :1

// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

// the count 
// the: 4
// "is: 3
// "sunny" : 2
// ,"day" :1

// traverse the map (value, string) heap, do it as a min heap with size k
// if larget size, we pop

// O(n) -> O(nlogk) heap traverse n times, size would be size k

class Solution {
public:
    struct CmpWorstTop {
        // return true 表示 a 的優先度比 b 低（會往後排）
        // 我們希望 top() 是 "最差":
        // cnt 小更差；cnt 同時，字典序大更差
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first;   // cnt 小的在 top
            return a.second < b.second; // 字典序大的在 top（所以 a<b 時，a 優先度更低）
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for (const auto &w : words) freq[w]++;

        priority_queue<pair<int,string>, vector<pair<int,string>>, CmpWorstTop> pq;

        // always push to let the heap decide
        // because it has better compare system
        // then only compare cnt
        for (auto& [w, c] : freq) {
            pq.push({c, w});
            if ((int)pq.size() > k) pq.pop(); // 丟掉最差
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end()); // 這次 reverse 才是對的（因為 pop 出來是差->好）
        return ans;
    }
};

