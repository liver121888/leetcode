class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        int res;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto x:mp){
            if(x.second > n/2){
                res =  x.first;
            }
        }
        return res;
    }
};