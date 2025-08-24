class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // subarray problem
        // must delete one element
        // 1 1 0 1
        // 0 1 1 1 0 1 1 0 1
        // 1 1 1

        // the potential longest one: entire array
        // 1 1 1 then we delete 1 element so ans is 2
        // two pointers

        // l = 0, r = 0
        // if >= two not one element, shrink
        // else expand and update the ans

        // 1 1 0 1
        // l = 0, r = 0
        // ans = -1
        // nonzerocnt = 0
        // ans = max(ans, r - l + 1 - 1) -> ans = 0

        // l = 0, r = 1
        // ans = 0
        // ans = max(ans, 1) -> ans = 1
        // nonzerocnt = 0

        // l = 0, r = 2
        // ans = 1
        // ans = max(ans, 3) -> ans = 2
        // nonzerocnt = 1

        int l = 0;
        int ans = -1;
        int nononeCnt = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 1) {


            } else {
                nononeCnt++;
                while (nononeCnt > 1) {
                    // shrink
                    if (nums[l] == 0)
                        nononeCnt--;
                    l++;
                }
            }
            ans = max(ans, r - l + 1 - 1);
        }

        // [0,1,1,1,0,1,1,0,1]
        // l = 0, r = 0
        // ans = -1
        // nonzerocnt = 1
        // ans = max(ans, r - l + 1 - 1) -> ans = 0

        // l = 0, r = 1
        // ans = 1
        // nonzerocnt = 1

        // l = 0, r = 4
        // nonzerocnt = 2 -> 1


        return ans;
    }
};