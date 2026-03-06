
// we only need to build the string
// return the len
// we can choose not to use some character
// but we can only have one odd cnt number
// other odd we can spread it on the side
// let's say the cnt is
// 3 4 6 7 5
// we can build 2 + 4 + 6 + 6 + 5
// if odd is there we +1
// other wise we add the /2 to the end

// s consists of lowercase and/or uppercase English letters only.
class Solution {
public:

    unordered_map<char, int> freq;

    int longestPalindrome(string s) {
        
        for (const auto& c : s) {
            freq[c]++;
        }
        
        int ans = 0;
        bool hasOdd = false;
        for (const auto& [c,cnt] : freq) {

            // Check if the frequency is even
            if (cnt % 2 == 0) {
                ans += cnt;
            } else {
                // If the frequency is odd, one occurrence of the
                // character will remain without a match
                ans += cnt - 1;
                hasOdd = true;
            }
        }
        // get the maxOdd cnt add 

        return hasOdd ? ans + 1 : ans;
    }
};