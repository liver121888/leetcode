
// minimum absolute distance
// there might be duplicate
// but it's in sorted order because we traverse
// in order
// keep vector of index and just take the latest one
// the latest one is gonna be the closest

// keep an hashmap (element, i), when we reverse the curr num
// and find out the reverse is in the map
// we return the abs distance

// largest distance will be n-1
// 0,....,n-1

class Solution {
public:

    int reverse(int x) {
        int result = 0;
        while (x) {
            result = result * 10 + x % 10;
            x/=10;
        }
        return result;
    }

    // 過度複雜了
    // 只要存最新的idx即可！
    // int minMirrorPairDistance(vector<int>& nums) {

    //     int n = nums.size();

    //     // base case: if empty, no mirror pair, return -1;
    //     if (n == 0)
    //         return -1;

    //     // init to impossible value
    //     // we keep taking the min
    //     // if no min exist, return -1;
    //     int minDist = n;

    //     unordered_map<int,vector<int>> e2ids;


    //     // 0 <= i < j < nums.length
    //     // so we need to move from the back
    //     for (int i = n-1; i >= 0; i--) {
    //         int element = nums[i];
    //         int mirrorPair = reverse(element);
    //         // deal with reverse is itself
    //         // is not applicable because 0 <= i < j
    //         // if (mirrorPair == element)
    //         //     return 0;
    //         if (e2ids.find(mirrorPair) != e2ids.end()) {
    //             minDist = min(minDist, e2ids[mirrorPair].back() - i);
    //         }
    //         e2ids[element].push_back(i);
    //     }
        
    //     return minDist == n ? -1 : minDist;
    // }


    // Input: nums = [12,21,45,33,54]
    // Output: 1

    // 0 <= i < j < nums.length
    // so we need to move from the back

    // Input: nums = [120,21]
    // Output: 1

    // Input: nums = [21,120]
    // Output: -1

    // Input: nums = [1]
    // Output: 0

    // Input: nums = []
    // Output: -1


    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y;
        };

        int n = nums.size();
        unordered_map<int, int> prev;
        // impossible value
        int ans = n;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (prev.count(x)) {
                ans = min(ans, i - prev[x]);
            }
            prev[reverseNum(x)] = i;
        }

        return ans == n ? -1 : ans;
    }


};