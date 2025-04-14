class Solution {
public:

    bool checkValid(int n_i, int n_j, int n_k, int a, int b, int c) {
        if (abs(n_i - n_j) > a)
            return false;
        if (abs(n_j - n_k) > b)
            return false;
        if (abs(n_i - n_k) > c)
            return false;
        return true;
    }

    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

        int result = 0;

        // brute force is possible: O(n^3)
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                for (int k = j + 1; k < arr.size(); k++) {
                    if (checkValid(arr[i], arr[j], arr[k], a, b, c))
                        result += 1;
                }
            }
        }
        return result;
        
    }
};