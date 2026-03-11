
// Follow up: Your algorithm's time complexity must be better than O(n log n),
//  where n is the array's size.

// we can count the array
// just use map so we also sort the elements by the freq
// 1 2 3
// 3 2 1

// we need top k

// keep a min heap
// keep size k
// we push then pop if size is greater

class Solution {
public:

    // O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }


        // 依照出現的freq幫num分組
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, cnt] : freq) {
            buckets[cnt].push_back(num);
        }

        vector<int> ans;
        for (int cnt = nums.size(); cnt >= 1 && ans.size() < k; --cnt) {
            for (int num : buckets[cnt]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }

        return ans;
    }


    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int> freq;
    //     for (const auto& num : nums) {
    //         freq[num]++;
    //     }

    //     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;


    //     for (const auto& [num, cnt] : freq) {

    //         pq.push({cnt, num});

    //         // if (pq.empty() || cnt > pq.top().first)

    //         if (pq.size() > k)
    //             pq.pop();

    //     }

    //     vector<int> ans;
    //     while (!pq.empty()) {
    //         int num = pq.top().second;
    //         ans.push_back(num);
    //         pq.pop();
    //     }
    //     return ans;

    // }
};