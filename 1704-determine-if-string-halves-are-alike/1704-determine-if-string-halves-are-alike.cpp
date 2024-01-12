class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        for (int i = 0; i < n/2; i++) {
            if (vowels.find(s[i]) != vowels.end())
                cnt++;
        }
        for (int i = n/2; i < n; i++) {
            if (vowels.find(s[i]) != vowels.end())
                cnt--;
        }
        return cnt == 0 ? true : false;
    }
};