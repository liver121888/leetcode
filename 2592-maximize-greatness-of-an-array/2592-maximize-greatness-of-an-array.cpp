
// we permute the array
// the number of indices that perm[i] > nums[i]
// return maximum possible greatness

// Example 1:
// Input: nums = [1,3,5,2,1,3,1]
// Output: 4
// [2,5,1,3,3,1,1]
// At indices = 0, 1, 3, and 4

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 3
// [2 3 4 1]

// 1 2 3 4
// 1 1 1 1
// we solve the smallest with the second smallest
// so we know we can get -> 3

// there might be repeating numbers
// we can count the frequency
// 1 2 3 5
// 3 1 2 1

// from here we have two pointers from front and back
// we know 2 + 1 = 3 -> so we can get 3 but this is not correct
// we can solve the 1 with 2 and 3
// and 5 can guarantee to save 1
// so ans is 3 + 1 = 4

class Solution {
public:

    // To get as many perm[i] > nums[i] as possible,
    // we will try to put smallest A[i] on the right.
    // So we iterate A, and check if it's greater than A[0].
    // If A[0] is done, we then try A[1] and so on.
    // So we can start with res = 0 and A[res] is the next element to compare.
    // Finally return res directly.
    // 就是選next greater來消掉現在在res的element

    // Imagine A is sorted,
    // and we try to satify as many as possible but k elements.
    // 選k個當lost cost
    // How will we arrange the list?
    // before: A[0] A[1] ... A[n - 1 - k]
    // after: A[k] A[1+k] ... A[n - 1]
    // where
    // A[0] < A[k]
    // A[1] < A[1 + k]
    // A[2] < A[2 + k]
    // ...
    // A[n - 1 - k] < A[n - 1]
    // Note that k need to be bigger than the biggest frequency of A[i],
    // otherwise there will be at least one A[i] == A[i + k].

    // 更白話的理解
    // 你可以把它想成：
    // 某個數字如果重複太多次
    // 它就像一坨很大的「堵塞」
    // 你必須留出足夠空間，才能讓這些重複值都被更大的數吃掉
    // 最大的那一坨重複值，決定了你最多會有多少個位置無法被打敗。
    // Time O(n)
    // Space O(n)

    int maximizeGreatness(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int a : nums)
            count[a]++;

        int mx = 0;
        for (auto& [num, cnt] : count) {
            mx = max(mx, cnt);
        }   


        return nums.size() - mx;
    }
};