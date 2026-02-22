// we need to find the peak element in an array
// we regard the edge as -inf
// the peak is strictly greater than its neighbors
// we return any peak

// nums = [1,2,3,1]
// 3 is peak, return index 2

// nums = [1,2,1,3,5,6,4]
//  index number 1 or index 5

// O(n), for each position we check the prev and next elements
// if we find a peak, we return the index
// if the index is 0 or n - 1, we only compare one side
// [1,2,3,1]
// 3 > 1, 3 > 2 -> return 
// l = 0, r = 3, mid = 1
// 1 2 1, greater to both side
// we shrink r

// l r mid one index different, and then we return the mid

// O(log n)
// [1,2,peak,1]
// nums = [1,peak,1,3,5,peak,4]
// before and after are both sorted

// [1,peak,1,3,5,peak,4]
// l = 0, r = 6, mid = 3

// we move one of the pointer until the current mid 
// l < mid < r
// mid > l, mid > r
// r < mid < l
// mid < l, mid < r
// we move the pointer until the peak is no longer the peak
// [1,2,3,1]
// l = 1, r = 1, mid = 2
// l = 2, mid = 3, r = 1 -> we chekc index we return mid


// [1,peak,1,3,5,peak,4]
//  1 1 4
// 1 5 4

// stack monotonic 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r-l)/2;
            // on a sloping down hill
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else 
                l = mid+1;
        }
        return l;
        
    }
};