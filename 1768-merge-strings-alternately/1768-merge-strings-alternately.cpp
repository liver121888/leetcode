
// O(mn), m n are the len for strings
// space: O(1), constant extra space

class Solution {
public:
    
    // 太精簡了
    // 厲害
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0;
        int j=0;
        while (i<word1.length() || j<word2.length()){
            if (i<word1.length()){
                ans.push_back(word1[i]);
                i++;
            }
            if(j<word2.length()){
                ans.push_back(word2[j]);
                j++;
            }
        }
        return ans;
    }

    // string mergeAlternately(string word1, string word2) {

    //     int len1 = word1.size();
    //     int len2 = word2.size();

    //     string result = "";
    //     int ptr1 = 0, ptr2 = 0;
    //     bool isTake1 = true;
    //     while (ptr1 < len1 && ptr2 < len2) {
    //         char curr = ' ';
    //         if (isTake1) {
    //             curr = word1[ptr1];
    //             ptr1++;
    //         } else {
    //             curr = word2[ptr2];
    //             ptr2++;
    //         } 
    //         result += curr;
    //         // cout << isTake1 << endl;
    //         isTake1 = !isTake1;
    //     }

    //     if (ptr1 < len1)
    //         result += word1.substr(ptr1);
    //     else {
    //         result += word2.substr(ptr2);
    //     }

    //     return result;
    // }
};