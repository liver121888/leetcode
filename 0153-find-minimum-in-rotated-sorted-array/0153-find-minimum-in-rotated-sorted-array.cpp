
// unique elements, return the minimum element of this array.

// [3,4,5,1,2]
// 1

// [4,5,6,7,0,1,2]
// 0

// [11,13,15,17]
// 11

// we want to find the minimum 
// what does it mean by finding the minimum

// we can have left and right ptr
// l is 3, r is 2, mid is 5
// we know the one with order is the leftside 
// l 3 r  5, mid is 4
// l = mid

// [11,13,15,17]
// l < mid < r
//  r = mid - 1;

// [3,4,5,1,2]
// 1
// l < mid > r
//  compare l and r

// [6,7,0,1,2,4,5]
// 0
// l > mid < r
//     compare l and r
 
// [3,4,5,1,2]
// l = 3
// mid = 5
// r = 2

// l = 1
// mid = 1
// r = 2

// l = 2
// mid = 2
// r = 2

// 只有兩個區段，這兩個也都是遞增
// [6,7,0,1,2,4,5] -> [6,7], [0,1,2,4,5]

// 兩情況
// 1. mid在第一個遞增區段
// 2. mid在第二的遞增區段

// l r mid
// 1. mid > r
// 2. mid < r 

// [3,4,5,1,2]
// 1
// l = 3, mid = 5, r = 2
// mid > r
// l = 5 mid = 1 r = 2
// l = 1, mid = 1, r = 2
// l = 2, mid = 2, r = 2
// r = 1

// [4,5,6,7,0,1,2]
// 0
// l = 4, mid = 7, r = 2

// class Solution {
// public:
//     int findMin(vector<int>& nums) {

//         int l = 0, r = nums.size() - 1;
//         while (l <= r) {
//             int mid = l + (r-l)/2;
//             if (nums[mid] < nums[r]) {
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return nums[r];
//     }
// };


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};