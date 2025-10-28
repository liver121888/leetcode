class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        // we don't have to simulate the whole process
        // only think about picking a zero position and the left sum == right sum
        // can we allow +1 -1 diff, yes we can
        // [1 0 2 0 4] -> [1 0 2 0 3]
        // [1 0 3 0 3] -> [1 0 2 0 3]

        // [1 0 2 0 3]
        // [1 1 3 3 6]
        // [6 5 5 3 3]

        // [1 0 2 0 4]
        // [1 1 3 3 7]
        // [7 6 6 4 4]     

        // [2,3,4,0,4,1,0]
        // 2,5,9,9,13,14,14
        // 14,12,9,5,5,1,0   

        int n = nums.size();
        int ans = 0;
        if (n == 1)
            return nums[0] == 0 ? 2 : ans;

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        vector<int> suffixSum(n, 0);
        suffixSum[n-1] = nums[n-1];

        // prefix sum and suffix sum
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
            suffixSum[n-1-i] = nums[n-1-i] + suffixSum[n-1-(i-1)];
        }

        for (int i = 0; i < n; i++) {
            cout << prefixSum[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << suffixSum[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (prefixSum[i] == suffixSum[i]) {
                    ans += 2;
                } else if (abs(prefixSum[i] - suffixSum[i]) == 1) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};