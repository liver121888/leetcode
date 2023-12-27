class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l = 0; int res = 0;
        for (int r = 1; r < colors.length(); r++) {
            if (colors[l] == colors[r]) {
                if (neededTime[l] < neededTime[r]) {
                    res += neededTime[l];
                    l = r;
                } else {
                    res += neededTime[r];   
                }
            } else {
                l = r;
            }
        }
        return res;
    }
        
};