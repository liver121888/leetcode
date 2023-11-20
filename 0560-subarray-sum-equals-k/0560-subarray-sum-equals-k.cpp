class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> aMap;
        aMap[0] = 1;
        int ans = 0;
        int curSum = 0;
        int target = 0;
        for (auto num : nums) {
            curSum += num;
            target = curSum - k;
            if (aMap.find(target) != aMap.end())
                ans += aMap[target];
            aMap[curSum]++;
        }
        
        // for (auto& [k, v] : aMap) {
        //     cout << k << ' ' << v << endl;
        // }
        
        return ans;
    }
};