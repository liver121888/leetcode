

// unordered_map<int, vector<int>>
// each query take the number and iter through the array to get the sum
// O(n^2)


// is it possible O(n)?]
// some how we need a datastructure to
// O(1) get the difference

// Example 1:
// Input: nums = [1,3,1,1,2]
// Output: [5,0,3,4,0]

// 1: 0,2,3
// 2: 4
// 3: 1

// 0, 2, 5
// 5 = a + b + c
// 2 = b + c

// Since the indices within each group are sorted, we can split the sum into two parts:
// ai - aj, if j < i
// aj - ai if j > i
// we can get all the aj sum by prefix sum

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            // get the prefix sum
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;
            // 左sum: ai*i - i之前的sum = ai*i - Pi
            // 又sum: i之後的sum - ai*(m-i-1) = totalSum - (Pi + ai) - ai*(m-i-1)
            // 合：ai*i - Pi ＋ totalSum - (Pi + ai) - ai*(m-i-1) = totalSum - 2*pi + ai*(2i-m)
            // 非常厲害一次走完
            for (int i = 0; i < group.size(); i++) {
                res[group[i]] = total - prefixTotal * 2 + group[i] * (2 * i - group.size());
                prefixTotal += group[i];
            }
        }
        return res;
    }
};