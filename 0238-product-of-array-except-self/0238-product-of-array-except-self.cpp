// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {

//         // time: O(n), we cannot use division
//         // array is the product of the array but except the number itself

//         // 1,2,3,4
//         // 24, 12, 8, 6

//         // [-1,1,0,-3,3]
//         // [0,0,9,0,0]

//         // brute force
//         // i = 0
//         // times all numbers from 1 to n-1
//         // ...
//         // i = n-1
//         // all numbers from 0 to n-2
//         // time: O(n^2)
//         // space: O(1)

//         // 1, 2, 6, 24
//         // 24, 24, 12, 4

//         // x, x, 2 * 4 = 8, x
//         // 24, 1 * 12, 2 * 4, 24

//         // if we can use division
//         // 24 -> O(n)
//         // divide at each position -> O(n) 
//         // 24, 12, 8, 6
//         // time: O(n)
//         // space: O(1)

//         int n = nums.size();
//         vector<int> prefixP = vector<int>(n);
//         vector<int> suffixP = vector<int>(n);
//         prefixP[0] = nums[0];
//         suffixP[n - 1] = nums[n-1];
//         for (int i = 1; i < n; i++) {
//             prefixP[i] = prefixP[i-1] * nums[i];
//             suffixP[n-1 - i] = suffixP[n-1 - i + 1] * nums[n-1 - i];
//         }

//         // prefixP = 1
//         // suffixP = x, x, x, 4

//         // i = 1
//         // prefixP = 1,2
//         // suffixP = x, x, 3*4 = 12, 4


//         // 1, 2, 6, 24
//         // 24, 24, 12, 4

//         //exp: [24,12,8,6]

//         for (int i = 0; i < n; i++) {
//             if (i == 0)
//                 nums[i] = suffixP[i+1];
//             else if (i == n-1)
//                 nums[i] = prefixP[i-1];
//             else
//                 nums[i] = prefixP[i-1] * suffixP[i+1];
//         }




//         return nums;

//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // The length of the input array
        int length = nums.size();

        // The answer vector to be returned
        vector<int> answer(length);

        // answer[i] contains the product of all the elements to the left
        // Note: for the element at index '0', there are no elements to the
        // left, so answer[0] would be 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            // answer[i - 1] already contains the product of elements to the
            // left of 'i - 1' Simply multiplying it with nums[i - 1] would give
            // the product of all elements to the left of index 'i'
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R contains the product of all the elements to the right
        // Note: for the element at index 'length - 1', there are no elements to
        // the right, so R would be 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // For the index 'i', R would contain the
            // product of all elements to the right. We update R accordingly
            answer[i] = answer[i] * R;
            R *= nums[i];
        }

        return answer;
    }
};