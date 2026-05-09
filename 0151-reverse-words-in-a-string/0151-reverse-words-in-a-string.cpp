
// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

// we can traverse the string
// when we encounter the space
// we end the current string
// vector of string to store
// we reverse the vector
// or just use a stack to have LIFO
// then output the string
// time: O(n)
// space: O(n)
// edge case: s = ""
// edge case: s = "           "
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string curr = "";

        for (char c : s) {
            if (c != ' ') {
                curr += c;
            } else {
                if (!curr.empty()) {
                    st.push(curr);
                    curr = "";
                }
            }
        }

        if (!curr.empty()) {
            st.push(curr);
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();

            if (!st.empty()) {
                ans += " ";
            }
        }

        return ans;
    }
};

// built-in
// time: O(n)
// space: O(1) becuase in c++ stirng is mutable, 
// in python/java: O(n), they have immutable string
// class Solution {
// public:
//     string reverseWords(string s) {
//         // remove leading and trailing spaces
//         s.erase(0, s.find_first_not_of(' '));  // prefixing spaces
//         s.erase(s.find_last_not_of(' ') + 1);  // suffixing spaces

//         // split by spaces
//         istringstream iss(s);
//         vector<string> words;
//         copy(istream_iterator<string>(iss), istream_iterator<string>(),
//              back_inserter(words));

//         // reverse and join
//         reverse(words.begin(), words.end());
//         ostringstream oss;
//         copy(words.begin(), words.end() - 1,
//              ostream_iterator<string>(oss, " "));
//         oss << words[words.size() - 1];
//         return oss.str();
//     }
// };


// Reverse the Whole String and Then Reverse Each Word
// class Solution {
// public:
//     void reverseStr(string &s, int l, int r){
//         while(l<r){
//             swap(s[l], s[r]);
//             l++, r--;
//         }
//     }

//     string reverseWords(string s) {
//         int n = s.size();
//         reverse(s.begin(), s.end());

//         int start = 0;
//         for(int end=0; end<=n; end++){
//             if(end==n || s[end]==' '){
//                 reverseStr(s, start, end-1);
//                 start = end+1;
//             }
//         }

//         string ans = "";
//         int i=0;

//         while(i<n){
//             while(i<n && s[i]==' ') i++;

//             if(i>=n) break;
//             if(!ans.empty()) ans += " ";

//             while(i<n && s[i]!=' ') {
//                 ans += s[i];
//                 i++;
//             }
//         }
//         return ans;
//     }
// };
