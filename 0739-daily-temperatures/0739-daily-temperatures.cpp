// we need to solve for each idx
// if we can also record idx as a pair
// we can solve it as i - j
// have a stack
// check top
// if curr > top
// idx
// if curr < top
// push
// 73
// 74
// we solve and put 74
// 75 when we find 71
// push
// 75 71 69 72
// solve for 71 69
// we need to keep idx so we can get the correct number

class Solution {
public:

    // 73,0 
    // 74,1
    // 75,2
    // 71.3
    // 69,4
    // 72,5


    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            
            // if not empty, we need to comapre and push
            // if empty, we push

            int currTemp = temperatures[i];
            while (!st.empty()) {
                const auto& [temp, idx] = st.top();
                if (temp < currTemp) {
                    ans[idx] = i - idx;
                } else {
                    break;
                }
                st.pop();
            }

            st.push(make_pair(temperatures[i], i));

        }


        return ans;
    }
};