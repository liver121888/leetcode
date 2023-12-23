class Solution {
public:
    bool isPathCrossing(string path) {
        set<vector<int>> visited;
        vector<int>curPlace = {0, 0};
        visited.insert(curPlace);
        
        for (auto c : path) {
            switch(c) {
                case 'N':
                    curPlace[1]++;
                    break;
                case 'S':
                    curPlace[1]--;   
                    break;
                case 'E':
                    curPlace[0]++;
                    break;
                case 'W':
                    curPlace[0]--;
                    break;
                default:
                    break;
            }
            
            if (visited.contains(curPlace))
                return true;
            else
                visited.insert(curPlace); 
        }
        return false;
        
    }
};