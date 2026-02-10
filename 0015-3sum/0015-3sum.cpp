class Solution {
public:

    // string hash (int a, int b, int c) {
    //     return to_string(a) + " " + to_string(b) + " " + to_string(c);
    // }

    // vector<int> deHash(string s) {
    //     istringstream iss(s);
    //     int a, b, c;
    //     iss >> a >> b >> c;   // 會自動用空白分隔（多個空白也OK）
    //     return {a, b, c};
    // }

    // int binarySearch(const vector<int>& nums, int target, int l) {

    //     // find exact value
    //     int r = nums.size() - 1;
    //     while (l <= r) {

    //         int mid = l + (r-l)/2;
    //         if (target < nums[mid]) {
    //             r = mid - 1;
    //         } else if (target > nums[mid]) {
    //             l = mid + 1;
    //         } else {
    //             return mid;
    //         }
    //     }
    //     return -1;
    // }

    void twoSumII(const vector<int>& nums, int i, vector<vector<int>>& res) {

        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                res.push_back({nums[i], nums[l], nums[r]});
                // 找到一組了但可能有更多組
                // 縮減範圍
                l++;
                r--;
                // prevent duplicate
                // 繼續縮減範圍因為可能有很多同樣的在l的後面
                // 也可硬使用hash_set來避免
                // 但既然我們都sort了就沒必要用hash_set
                while (l < r && nums[l] == nums[l - 1])
                    l++;
            }
        } 
    }


    vector<vector<int>> threeSum(vector<int>& nums) {

        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // unordered_set<string> triplets;

        // // we fix two numbers from the list
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         // nums[i] + nums[j] + nums[k] == 0
        //         // search for the third one
        //         int k = binarySearch(nums, -nums[i]-nums[j], j+1);
        //         if (k != -1) {
        //             // cout << i << j << k << endl;
        //             triplets.insert(hash(nums[i], nums[j], nums[k]));
        //         }
        //     }
        // }

        // vector<vector<int>> ans;
        // for (const auto& triplet : triplets) {
        //     ans.push_back(deHash(triplet));
        // }
        // return ans;

        // [-1,0,1,2,-1,-4]
        // -4, -1, -1, 0, 1, 2

        // -1 -1 2


        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                continue;

            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSumII(nums, i, res);
            }

        }
        return res;
    }
};