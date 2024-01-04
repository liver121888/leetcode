class Solution {
public:
    int ans;
    int cnt;
    
    int minOperations(vector<int>& nums) {
        // unordered_map<int, int> aMap;
        // for (auto num : nums) {
        //     aMap[num]++;
        // }
        sort(nums.begin(), nums.end());
        // for (auto element : nums) {
        //     cout << element << " ";
        // }   
        this->cnt = 0;
        int lastNum = -1;
        this->ans = 0;
        
        // if u conclude from table, u can see that except 1 all numbers are valid
        // for (auto num : nums) {
        //     // cout << this->cnt << endl;
        //     if (num != lastNum && lastNum != -1) {
        //         if (helper() == -1)
        //             return -1;
        //     } else {
        //        this->cnt++; 
        //     }
        //     lastNum = num;
        // }
        // if (helper() == -1)
        //     return -1;
                
        for (auto num : nums) {
            // cout << this->cnt << endl;
            if (num != lastNum && lastNum != -1) {
                if (cnt == 1)
                    return -1;
                this->ans += ceil((double)(this->cnt) / 3);
                this->cnt = 1;

            } else {
               this->cnt++; 
            }
            lastNum = num;
        }
        
        if (cnt == 1)
            return -1;
        this->ans += ceil((double)(this->cnt) / 3);

        return this->ans;        
    }
    
    // int helper() {
    //     if (this->cnt % 3 == 0) {
    //         this->ans += this->cnt / 3;
    //         this->cnt = 1;
    //     } else if (this->cnt % 3 == 2) {
    //         this->ans += this->cnt / 3 + 1;
    //         this->cnt = 1;
    //     } else if (this->cnt % 2 == 0) {
    //         this->ans += this->cnt / 2;
    //         this->cnt = 1;
    //     } else {
    //         return -1;
    //     }
    //     return 0;
    // }
    
};