class Solution {
public:
    void reverseString(vector<char>& s) {
        // int left = 0;
        // int right = s.size() - 1;
        // while (left < right) {
        //     char temp = s[left];
        //     s[left] = s[right];
        //     s[right] = temp;    
        //     left++;
        //     right--;
        // }
        
        // reverse(s.begin(), s.end());
        
        for (int i = 0; i < s.size()/2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
        
    }
};