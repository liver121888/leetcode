// Input: heights = [10,6,8,5,11,9]
// Output: [3,1,2,1,1,0]
// Explanation:
// Person 0 can see person 1, 2, and 4. it cannot see person 3
// Person 1 can see person 2.
// Person 2 can see person 3 and 4.
// Person 3 can see person 4.
// Person 4 can esee person 5.
// Person 5 can see eno one since nobody is to the right of them.

// Example 2:
// Input: heights = [5,1,2,3,10]
// Output: [4,1,1,1,0]

// The values of heights are unique.

// brute-forece
// i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
// for each i, we iterate the j that is larger than i
// for each j, we can see if we can see the j
// i = 0, [0,1,1,0,1,0] -> the number is 3
// time complextiy: O(n^2)


// stack, monotanic stack, decreasing stack
// [0,1] <- 2
// 6 < 8
// time: O(n)
// space: O(n)

#include <iostream>
#include <vector>
#include<stack>

using namespace std;

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int>& heights) {

    int n = heights.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int j = 0; j < n; ++j) {
        // 所有比 heights[j] 矮的，在 stack top 的那些都能看到 j
        while (!st.empty() && heights[st.top()] < heights[j]) {
            ans[st.top()]++;
            st.pop();
        }

        // 如果還有一個更高的在左邊（stack top），他也能看到 j
        if (!st.empty()) {
            ans[st.top()]++;
        }

        st.push(j);
    }


    return ans;
  }
};