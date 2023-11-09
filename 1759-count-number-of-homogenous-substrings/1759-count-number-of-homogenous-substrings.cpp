class Solution {
public:
    int countHomogenous(string s) {
        // follow the hint in solution
        int ans = 0;
        int currStreak = 0;
        unsigned long long MOD = 1e9 + 7;
        for (int i=0; i < s.length(); i++) {
            if (i == 0 || s[i] == s[i - 1]) {
               currStreak = currStreak % MOD;
                currStreak++; 
            }
            else
                currStreak = 1;

            ans = ans % MOD;
            ans = (ans % MOD + currStreak % MOD) % MOD;
        }        
        return ans;
    }
};