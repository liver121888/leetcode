
// Example 1:
// Input: moves = "L_RL__R"
// Output: 3
// Explanation: The furthest point we can reach from the origin 0 is point -3 
// through the following sequence of moves "LLRLLLR".

// Example 2:
// Input: moves = "_R__LL_"
// Output: 5
// Explanation: The furthest point we can reach from the origin 0 is point -5 through the following sequence of moves "LRLLLLL".

// Example 3:
// Input: moves = "_______"
// Output: 7
// Explanation: The furthest point we can reach from the origin 0 is point 7 through the following sequence of moves "RRRRRRR".

// ""
// "[", it's not R L _

// if R -> RCnt++
// L -> LCnt++
// n -> n - RCnt - LCnt = UnderCnt

// time: O(n), n is the size of the string
// space: O(1)

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int n = moves.size();
        int rCnt = 0; 
        int lCnt = 0;
        for (const auto& c : moves) {
            if (c == 'R') {
                ++rCnt;
            } else if (c == 'L') {
                ++lCnt;
            } else if (c != '_' ) {
                throw invalid_argument("input must be R, L, _!");
            }
        }

        return rCnt > lCnt ? rCnt-lCnt+(n-rCnt-lCnt) : lCnt-rCnt+(n-rCnt-lCnt);
        
    }
};