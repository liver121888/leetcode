class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        stack<pair<int,int>> st;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top().second < temperatures[i]) {
                int prevDay = st.top().first;
                int prevTemp = st.top().second;
                st.pop(); 
                ans[prevDay] = i - prevDay;
            }
            st.push({i, temperatures[i]});                

        }
 
        return ans;
        
    }
};