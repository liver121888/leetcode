// Input: asteroids = [5,10,-5]
// Output: [5,10]
// positive means to the right
// negative means to the left

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Example 3:
// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

// Example 4:
// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]
// Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.

// we can solve this using a stack
// stack.top() > 0 incoming is negative
// check whether it can pop all the way or it will stop and maybe be destryed at some point

// if < and incoming is negative or if < and the incoming is positive

// logic
// while the stack is non empty and stack.top > 0 and the incoming is negative
// of same size pop and don't push
// incoming is larger we pop
// incoming is smaller just don't push
// else 
// push the stack in 


// [3,5,-6,2,-1,4]

// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {

//         stack<int> st;
//         for (const auto& asteroid : asteroids) {
//             bool shouldPush = true;
//             while (!st.empty() && st.top() > 0 && asteroid < 0) {
//                 if (st.top() == abs(asteroid)) {
//                     st.pop();
//                     shouldPush = false;
//                     break;
//                 } else if (st.top() > abs(asteroid)) {
//                     shouldPush = false;
//                     break;
//                 } else {
//                     shouldPush = true;
//                     st.pop();
//                 }
//             }

//             if (shouldPush)
//                 st.push(asteroid);
//         }

//         vector<int> ans;
//         while (!st.empty()) {
//             ans.push_back(st.top());
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// 巨乾淨寫法
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // 用 vector 當 stack，最後不用再倒出來 reverse
        for (int a : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.back() > 0 && a < 0) {
                int top = st.back();
                if (top < -a) {              // top 爆
                    st.pop_back();
                    continue;
                } 
                if (top == -a) {             // 兩個都爆
                    st.pop_back();
                }
                alive = false;               // a 爆 or 已處理完(相等也算 a 爆)
            }

            if (alive) st.push_back(a);
        }
        return st;
    }
};