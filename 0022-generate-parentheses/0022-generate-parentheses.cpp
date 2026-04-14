
// Given n pairs of parentheses, write a function to 
// generate all combinations of well-formed parentheses

// we have to put an open bracket at first
// and then we can choose when to close it
// at any given state, the ( and ) should have equal counts
// or you can say ) cnt cannot be larger than ( cnt
// and the ( canot be larger than n
// the recursion ends when the size is n*2

// time: O(2^n)
// space: O(n) for temp

class Solution {
public:

    vector<string> ans;

    void backtrack(string s, int n, int openCnt, int closeCnt) {

        // base case: judge by size, when i+1 > 2*n
        if (openCnt + closeCnt == 2 * n) {
            ans.push_back(s);
            return;
        }


        // if (openCnt == n) {
        //     backtrack(s+')', n, openCnt, closeCnt+1);
        //     return;
        // }

        // if (closeCnt <= openCnt) {
        //     backtrack(s+')', n, openCnt, closeCnt+1);
        //     backtrack(s+'(', n, openCnt+1, closeCnt);
        // }

        // clean version
        if (openCnt < n) {
            backtrack(s+'(', n, openCnt+1, closeCnt);
        }

        if (openCnt > closeCnt) {
            backtrack(s+')', n, openCnt, closeCnt+1);
        }


    }

    vector<string> generateParenthesis(int n) {
        ans.clear(); 
        string state = "";
        backtrack(state, n, 0, 0);
        return ans;
    }
};
