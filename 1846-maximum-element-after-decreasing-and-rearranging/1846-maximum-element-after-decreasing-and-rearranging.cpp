class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if (arr.size() == 1)
            return 1;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size()-1; i++) {
            if (i == 0)
                arr[i] = 1;
            
            if (arr[i+1] - arr[i] > 1)
                arr[i+1] = min(arr[i] + 1, arr[i+1]);

        }
        int diff = arr[0] - 1;
        return arr[arr.size()-1] - diff;
    }
};