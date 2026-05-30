class Solution {
public:
    // 2 -> 4 -> 16 -> 37 -> 58 -> 64 + 25 -> 89 -> 1 4 5 -> 42 -> 20 -> 4
    // we need to track the numbers that we seen
    // can recursion call

    // time: 
    // space: 

    unordered_set<int> visited;

    bool isHappy(int n) {

        if (n == 1)
            return true;
        // cout << n << endl;
        visited.insert(n);     

        int result = 0;
        while (n) {
            result += (n % 10) * (n % 10);
            n /= 10;
        }

        if (visited.find(result) != visited.end())
            return false;
        return isHappy(result);
        
    }
};