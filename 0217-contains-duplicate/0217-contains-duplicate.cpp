class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> cnts;
        for (auto num : nums) {
            if (cnts.find(num) == cnts.end())
                cnts[num]++;
            else
                return true;
        }
        return false;
        
    }
};