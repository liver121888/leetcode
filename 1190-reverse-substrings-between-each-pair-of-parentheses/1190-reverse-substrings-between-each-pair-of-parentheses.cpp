class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> temp;
        queue<char> temp2;
        // (
        // ): pop till prev (
        // abcd: push
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                while (temp.top() != '(') {
                    cout << temp.top() << endl;
                    temp2.push(temp.top());
                    temp.pop();
                }
                // pop out (
                temp.pop();
                
                while (temp2.size() > 0) {
                    cout << temp2.front() << endl;
                    temp.push(temp2.front());
                    temp2.pop();
                }
            } else {
                temp.push(s[i]);        
            }
        }
        
        string result = "";
        while (temp.size() > 0) {
            result += temp.top();
            temp.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};