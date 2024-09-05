class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int sum = mean * (m + n);
        cout << sum << "\n";
        for (int roll : rolls) {
            sum -= roll;
        }
        
        if (sum < n || sum > 6*n)
            return {};
        
        int cnt = 0;
        while (sum - n > 0) {
            sum -= n;
            cnt += 1;
        }
        cout << cnt << "\n";
        vector<int> ans(n, cnt);
        for (int i = 0; i < sum; i++) {
            ans[i] = ans[i] + 1;
        }
        return ans;    
    }    
};