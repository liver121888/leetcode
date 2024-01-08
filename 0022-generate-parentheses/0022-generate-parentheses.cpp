class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        vector<char> curString;
        backTracking(ans, curString, 0, 0, n);
        return ans;
    }
    
    void backTracking(vector<string>& ans, vector<char>& curString, int openCnt, int closeCnt, int& n) {
        if (openCnt == closeCnt && openCnt == n) {
            ans.push_back(string(curString.begin(), curString.end()));
        }
        
        if (openCnt < n) {
            curString.push_back('(');
            backTracking(ans, curString, openCnt + 1, closeCnt, n);
            curString.pop_back();          
        }

        if (closeCnt < openCnt) {
            curString.push_back(')');
            backTracking(ans, curString, openCnt, closeCnt + 1, n);
            curString.pop_back();
        }        
    }
};