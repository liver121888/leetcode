// we can check every index on s to see if it includes p
// O(m*n)
// if s is of size m and if p is of size of n

// if p.len > s.len, we know it's impossible

// we can do a sliding window method
// we count the freq in p
// and traverse s using sliding window
// O(max(m*O(1), n))


class Solution {
public:


    vector<int> findAnagrams(string s, string p) {

        int m = s.length();
        int n = p.length();

        if (n > m)
            return {};

        // lowercase English letters.
        vector<int> cnts(26);
        for (const auto & c : p) 
            cnts[c - 'a']++;

        vector<int> ans;
        vector<int> currCnts(26);
        int l = 0;
        for (int r = 0; r < m; r++) {
            currCnts[s[r] - 'a']++;

            // don't need to remove by charater, just simply shrink to the same size
            // while (currCnts[s[r] - 'a'] > cnts[s[r] - 'a']) {
            //     currCnts[s[l] - 'a']--;
            //     l++;
            // }

            // remove one letter 
            // from the left side of the window
            if (r - l + 1 > n) {
                currCnts[s[l] - 'a']--;
                l++;
            }

            bool isAnagram = true;
            for (int i = 0; i < 26; i++) {
                if (currCnts[i] != cnts[i])
                    isAnagram = false;
            }
            if (isAnagram)
                ans.push_back(l);

        }
        

        return ans;
        
    }

};