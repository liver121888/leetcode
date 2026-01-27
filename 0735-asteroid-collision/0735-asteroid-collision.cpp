// If two asteroids meet, the smaller one will explode. 
// If both are the same size, both will explode. 
// Two asteroids moving in the same direction will never meet.

// why this is a stack problem
// the cancellation reminds me of the parenthesis stack

// we can use a stack
// if stack is empty -> push
// if not -> check sign -> if is a positive and curr is negative -> check
// if same size -> both explode
// if negative bigger -> pop until stopped or same sign
// if positive bigger -> don't push
// if a negative -> push
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> state;
        for (int& asteroid : asteroids) {
            int flag = 1;
            while (!state.empty() && state.top() > 0 && asteroid < 0) {

                if (abs(state.top()) < abs(asteroid)) {
                    state.pop();
                    continue;
                }
                else if (abs(state.top()) == abs(asteroid)) {
                    state.pop();
                } 

                // If we reach here, the current asteroid will be destroyed
                // Hence, we should not add it to the stack
                flag = 0;
                break;
            }
            if (flag) {
                state.push(asteroid);
            }

        }

        // [5,10,-5]
        // 5, 10 

        // [8,-8]
        // []

        // [10,2,-5]
        // [10]

        // [3,5,-6,2,-1,4]
        // -6 2 4​​​​​​​

        // Add the asteroids from the stack to the vector in the reverse order.
        vector<int> remainingAsteroids (state.size());
        for (int i = remainingAsteroids.size() - 1; i >= 0; i--){
            remainingAsteroids[i] = state.top();
            state.pop();
        }
        
        return remainingAsteroids;

    }
};