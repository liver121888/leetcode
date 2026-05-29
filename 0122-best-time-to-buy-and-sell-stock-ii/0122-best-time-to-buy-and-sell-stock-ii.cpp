// we can buy and sell at the same day
// we can hold only one stock at a time
// we want to maximize the total profit
// we can try to solve this using stack
// we try to maintain
// the price in the stack is increasing
// we can push -1 to indicate the start of the stack
// assume the price >= 0
// -1, 7 <- 1
// 1 < 7, so we need to conclude 7
// nothing so 0 profit, push 1 in
// -1, 1 5 <- 3
// any edge case
// 1 2 8 9 2 10000
// how can I prove
// yes, if we view it graphically
// 1-9 as a block, whatever number after 9 is <= 9
// 1 to 10000 creates a diff
// but if you take 1-9 then take <= 9 to 10000
// you can take more in the global

// [7,1,5,3,6,4]
// 4 + 3 = 7

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        stack<int> st;
        // use -1 to indicate the end
        int ans = 0;
        for (int price : prices) {
            if (!st.empty() && price < st.top()) {
                int currHigh = st.top();
                int currLow = st.top();
                while (!st.empty()) {
                    currLow = st.top();
                    st.pop();
                }
                ans += currHigh-currLow;
            }
            st.push(price);
        }
        
        // for the last time
        if (!st.empty()) {
            int currHigh = st.top();
            int currLow = st.top();
            while (!st.empty()) {
                currLow = st.top();
                st.pop();
            }
            ans += currHigh-currLow;
        }


        return ans;
    }
};