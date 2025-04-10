class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        unordered_set<int> st;
        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.insert(x);
            }
        }
        return st.size();


        // sequence is not important
        // each operation: select h that is valid, set all number to h

        // [2 4 5 5 5], k = 2
        // need minOp
        // if k is possible, select k directly
        // select 4 -> [2 4 4 4 4]
        // select 2 -> [2 2 2 2 2]

        // [2 4 5 5 6]
        // we cannot select 4 because there is one more

        // [2 1 2], k = 2
        // -1 because impossible

        // sort(nums.begin(), nums.end());

        // cnts -> freq of all the elements

        // set all the largest number to second largest number
        // repeat until we set all numbers to k

        // 1 <= nums[i] <= 100
        vector<int> cnts(100 + 1);

        // calc the freq
        for (auto num : nums) {
            cnts[num] += 1;
        }
        
        int ans = 0;
        for (int i = 1; i < cnts.size(); i++) {

            if (cnts[i] != 0) {
                if (i < k) {
                    return -1;
                } else if (i > k) {
                    ans++;
                } 
                // do nothing if i == k
            }

        }

        // [2 4 5 5 5], k = 2
        // 1 1 3
        // i == 4
        // ans = 1
        // i == 5
        // ans = 2

        // [2 1 2], k = 2
        // i == 1, return -1

        // [9 7 5 3]
        // 1 1 1 1 k = 1
        // 3 -> ans++;
        // 5 -> ans++;
        // return 4

        // m == 100
        // O(n + m)
        // O(m)

        return ans;
    }
};