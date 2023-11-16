class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> numSet;
        for (auto num : nums) {
            numSet.insert(stoi(num, 0, 2));
        }
        
        for (int i = 0; i <= n; i++) {
                if (numSet.find(i) == numSet.end()) {
                    string ans = bitset<16>(i).to_string();
                    return ans.substr(16 - n);            
                }
        }
        return "";
    }
};