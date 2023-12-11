class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        int tmp {}, rest {};
        vector<int> ans {};
        
        map<int, int> aMap;
        
        // we could use vector.at() or indexing, at() method would do 
        // boundary check while indexing would not. Here we use indexing 
        // because it's faster 
        for (int i = 0; i < length; i++) {
            aMap[nums[i]] = i;            
        }
        
        for (int i = 0; i < length; i++) {
            rest = target - nums.at(i);
            if (aMap.find(rest) != aMap.end() && aMap[rest] != i) {
                ans.push_back(i);
                ans.push_back(aMap[rest]);
                return ans;
            }
        }
        return ans;
    }
};