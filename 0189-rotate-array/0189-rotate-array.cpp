// index 0 -> index 3
// [1,2,3,4,5,6,7] n = 7

// we can create a new array
// and we index the original array
// [, , , 1, 2, 3, 4]
// when over bound, we fill the front part
// [5, 6, 7, 1, 2, 3, 4]
// O(n) time
// O(n) space

// we can do iteratively two pointers
// take the one in the back, and simulate the whole process
// O(n^2) time
// O(1) space

// we can do a two pointer
// [1,2,3,4,5,6,7]
//  l = 0, r = 3


// we foound 1 it goes to 4, 
// we found 4, it goes to 7,
// we found 7 it  to 3
// 3 goest to 6
// 6 goes to 2
// 2 goest 5
//  5 goest to 1


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        int count = 0;
        int startIdx = 0;

        while (count < n) {
            int currentIdx = startIdx, prevNum = nums[startIdx];
            do {
                int nextIdx = (currentIdx+k) % n;
                int tmp = nums[nextIdx];
                nums[nextIdx] = prevNum;
                prevNum = tmp;
                currentIdx = nextIdx;
                count++;
            } while (startIdx != currentIdx);
            startIdx++;
        }

    }
};