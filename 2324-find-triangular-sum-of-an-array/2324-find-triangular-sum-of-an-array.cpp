class Solution {
public:

    int triangularSum(vector<int>& nums) {
        // brute force
        // create new array
        // sum
        // time: O(n^2)
        // space: O(n^2)

        // constraint is small
        // let's try brute force first

        auto temp = nums;
        while (temp.size() != 1) {
            auto thisLayer = vector<int>();
            for (int i = 1; i < temp.size(); i++) {
                thisLayer.push_back((temp[i - 1] + temp[i]) % 10);
            }
            temp = thisLayer;
        }

        return temp[0];


    }
};