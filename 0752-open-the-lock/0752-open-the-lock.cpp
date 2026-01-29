/*

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of 'deadends' dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

*/

// we can model the states as a node in the graph
// we start from node 0000
// deadends -> obstacles
// each move we can +1 or -1 each digit, we need to wrap around 0 - 1 -> 9
// we can use bfs to find the minimum nums of moves

// we have 4 digits with 10 possible numbers -> if we consider this constant O(1)
// time complexity: O(n)
// space complexity: O(n)

#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// 0000
// state = {0,0,0,0}

class Solution {

public:

    struct node {
        string s;
        int step;
    };

    const vector<vector<int>> directions = {{-1, 0, 0, 0}, {1, 0, 0, 0},
        {0, -1, 0, 0},{0, 1, 0, 0}, {0, 0, -1, 0}, {0, 0, 1, 0},
        {0, 0, 0, -1}, {0, 0, 0, 1}};

    // helper to wrap around
    string helper(const string& s) {
        // ascii 0 ... 9 is continuous
        // minus - '0' to see if it's in the correct range
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' < 0)
                result += '9';
            else if (s[i] - '0' > 9)
                result += '0';
            else
                result += s[i];

        }
        return result;
    }

    int openLock(vector<string>& deadends, string target) {

        // 把 vector 變成 set/unordered_set（去重+快速查詢）
        unordered_set<string> obstacles(deadends.begin(), deadends.end());
        // for (auto d : deadends) {
        //     obstacles.insert(d);
        // }

        if (obstacles.find(target) != obstacles.end())
            return -1;
        
        if (obstacles.find("0000") != obstacles.end())
            return -1;
        

        // start the bfs
        queue<node> q;
        q.push({"0000", 0});

        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()) {

            // poll out a node
            node curr = q.front();
            q.pop();

            if(curr.s == target)
                return curr.step;

            // model state transition
            for (auto dir : directions) {

                string newState = "";
                for (int i = 0; i < 4; i++) {
                    newState += curr.s[i] + dir[i];
                }
                newState = helper(newState);

                // check if valid
                if (obstacles.find(newState) == obstacles.end() && 
                    visited.find(newState) == visited.end()) {
                    // not visited not obstacle
                    q.push({newState, curr.step+1});
                    visited.insert(newState);
                }
            }
        }
        
        return -1;
    }

};