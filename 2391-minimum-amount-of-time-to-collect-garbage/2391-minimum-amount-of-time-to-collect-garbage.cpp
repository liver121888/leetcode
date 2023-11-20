class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int m = 0;
        int p = 0;
        int g = 0;
        int ans = 0;
        
        for (int i = 1; i < n - 1; i++) {
            travel[i] = travel[i - 1] + travel[i];
        }
        // for (auto t : travel) {
        //     cout << t << ' ';
        // } 
        
        
        for(int i = 0; i < n; i++) {
            auto assort = garbage[i];           
            for (auto type : assort) {
                // cout << ans << endl;
                if (i == 0) {
                    ans += 1;                    
                } else {
                    switch(type) {
                        case 'M':
                            if (m == 0)
                                ans += travel[i - 1] + 1;
                            else                            
                                ans += travel[i - 1] - travel[m - 1] + 1;
                            m = i;
                            break;
                        case 'P':
                            if (p == 0)
                                ans += travel[i - 1] + 1;
                            else
                                ans += travel[i - 1] - travel[p - 1] + 1;
                            p = i;                        
                            break;
                        case 'G':
                            if (g == 0)
                                ans += travel[i - 1] + 1;
                            else                                
                                ans += travel[i - 1] - travel[g - 1] + 1;
                            g = i;   
                            break;
                        default:
                            break;
                    }                    
                }
            }  
        }
        return ans;
    }
};