class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> cnts;
        int n = arr.size();
        for (auto i : arr) {
            cnts[i] += 1;
            if (cnts[i] > n/4)
                return i;
        }
        return 0;        
    }
};