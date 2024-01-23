class Solution {
public:
    int maxLength(vector<string>& arr) {
        unordered_set<int> curState;
        return dfs(arr, curState, 0);
    }
    
    int dfs(vector<string>& arr, unordered_set<int>& curState, int i) {
        
        if (i == arr.size())
            return curState.size();
        
        // Create a temporary set to store the current state
        unordered_set<int> tempState = curState;  
        
        bool skip = false;
        
        // Select cur string
        for (auto c : arr[i]) {
            if (tempState.find(c - 'a') != tempState.end())
                skip = true;
            tempState.insert(c -'a');
        }
        
        int select = !skip ? dfs(arr, tempState, i + 1) : 0;

        // Not select cur string
        int notSelect = dfs(arr, curState, i + 1);        
        
        return max(select, notSelect);
    }    
    
};