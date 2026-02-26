// return the area of the largest rectangle in the histogram.
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// because 6 > 5, so we can have 2 * 5 = 10

// every histogram itself is the rectangle
// we are finding
// a subarray that max(min(subarray_elements) * (r - l +1))
// brute-force every subarray and calculate the max area

class Solution {
public:

    // better brute-force
    // int largestRectangleArea(vector<int>& heights) {
    //     size_t max_area = 0;
    //     for (size_t i = 0; i < heights.size(); i++) {
    //         int min_height = INT_MAX;
    //         for (size_t j = i; j < heights.size(); j++) {
    //             // for (size_t k = i; k <= j; k++) {
    //             //     min_height = min(min_height, heights[k]);
    //             // }
    //             min_height = min(min_height, heights[j]);
    //             max_area = max(max_area, min_height * (j - i + 1));
    //         }
    //     }
    //     return max_area;
    // }

    int largestRectangleArea(vector<int>& heights) {

        // we keep a monotonic stack
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            
            // 新來的histogram沒有比較高的時候，可結算
            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                // current height: 如果current柱子當作最矮的話
                // 那我的界就是在左右邊比我更矮的
                int current_height = heights[st.top()];
                st.pop();
                int current_width = i - st.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            st.push(i);
        }

        // 最後再算一次確保算完
        while (st.top() != -1) {
            int current_height = heights[st.top()];
            st.pop();
            int current_width = heights.size() - st.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
};