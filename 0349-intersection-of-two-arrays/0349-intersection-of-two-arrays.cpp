
// we can use unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        if (m < n)
            return intersection(nums2, nums1);

        unordered_set<int> set1(nums1.begin(), nums1.end());

        unordered_set<int> ans;
        for (int num : nums2) {
            if (set1.count(num))
                ans.insert(num);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};