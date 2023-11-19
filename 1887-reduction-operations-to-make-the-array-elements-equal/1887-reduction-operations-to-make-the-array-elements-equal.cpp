class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> aMap;

        int order = -1;
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            // cout << order << endl;
            if (last != nums[i]) {
                // cout << "find" << endl;
                order += 1;
                aMap[order] = 1;
            } else
                aMap[order] += 1;
            last = nums[i];
        }
        
        if (order == 0)
            return 0;
        
        // for (auto& it : aMap) {
        //     cout << it.first << ' ' << it.second << endl;
        // }
            
        
        int ans = 0;
        for (auto& it : aMap) {
            // cout << it.first << ' ' << it.second << endl;
            if (it.first == 0)
                continue;
            ans += it.second*it.first;
        }
        return ans;
    }
};