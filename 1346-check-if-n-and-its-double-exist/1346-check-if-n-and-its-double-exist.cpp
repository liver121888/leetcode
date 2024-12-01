class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int, int> aMap;
        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] % 2 == 0 && aMap.find(arr[i]/2) != aMap.end())
                return true;
            
            if (aMap.find(2 * arr[i]) != aMap.end())
                return true;
            
            aMap[arr[i]] = i;
        }
        return false;
        
    }
};