class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<int> temp;
        vector<bool> ans;
        bool check = true;
    
        for (int i = 0; i < m; i++) {
            temp.clear();
            for (int j = l[i]; j <= r[i]; j ++) {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            check = true;
            
            for (int k = 1; k < temp.size(); k++) {
                if (temp[k] - temp[k - 1] != temp[1] - temp[0]) {
                    check = false;
                    break;               
                }
            }            
            ans.push_back(check);
        }       
        return ans;
    }
};