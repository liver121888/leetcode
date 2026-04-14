
//  return all possible letter combinations that the number could represent. 
// Return the answer in any order.

// we can do a backtracking algorithm
// a unorderred_map to record the relation
// recursion
// 3 - 4
// time: O(4^n * n)
// space: O(n)

class Solution {
public:

    const unordered_map<char, vector<char>> keyboard = {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r', 's'}},
        {'8', {'t','u','v'}},
        {'9', {'w','x','y','z'}}
    };

    vector<string> ans;

    void backtrack(vector<char>& state, string digits, int i) {

        // base case
        if (i == digits.length()) {
            string temp = "";
            for (const auto& c : state) {
                temp += c;  
            }
            ans.push_back(temp);
            return;
        }

        char currDigit = digits[i];
        // cout << currDigit << endl;
        for (const auto& c : keyboard.at(currDigit)) {
            state.push_back(c);
            backtrack(state, digits, i+1);
            // restore state
            state.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        if (digits.length() == 0) {
            return ans;
        }
        vector<char> state;
        backtrack(state, digits, 0);
        return ans;
    }
};