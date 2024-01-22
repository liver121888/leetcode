class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        set<int> aSet;
        vector<int> ans;
        
        int numSum = 0;

        for (auto n : nums) {
            if (aSet.find(n) == aSet.end())
                aSet.insert(n);
            else {
                ans.push_back(n);
            }
            numSum += n;
        }
        
        ans.push_back(-(numSum - (n + 1) * n / 2 - ans[0]));
        return ans;
    }
};