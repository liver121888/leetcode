// // how do we trap one water?
// // 1 0 1 will trap one
// // 2 1 0 1 3 will trap 1 + 2 + min(2, 3)
// // finding next greater element to right/left of ith position of array
// // so when we have 2 we look next see if it's larger or smaller
// // so I think we can view this problem as segments
// // a segment is when it decrease and then increase
// // we then calculate this section as
// // 1st section 1 0 2 -> 1
// // 2nd section 2 1 0 1 3 -> 4
// // index 4 - 0 - 1 = 3 in between
// // if the obstacles are not there, we could have get 3 * min(3, 2) = 6
// // but there are two obstacles, so 6- 2 = 4
// // we keep doing this until we reach the end

// // how do we find the section
// // we can have a flag to confirm the down trend
// // and when we see the up trend and see another down trend
// // we stop


// // 1 0 2
// // 2,1,0,1,3

// int calculateWater(vector<int>& sub) {
//     auto min_it = min_element(sub.begin(), sub.end());

//     int adj = 0;
//     for (int i = 1; i < sub.size()-1; i++){
//         adj += sub[i];
//     }
//     return min(sub[0], sub[sub.size()-1]) * (sub.size() - 2) - adj;
// }


// class Solution {
// public:
//     int trap(vector<int>& height) {

//         // vector<int> test = {1, 0, 2};
//         // cout << calculateWater(test) << endl;
//         // test = {2,1,0,1,3};
//         // cout << calculateWater(test) << endl;

//         int ans = 0;
//         int prev = height[0];
//         // 0, not yet decreasing
//         // 1, decreasing
//         // 2. increasing
//         // if we found another,
//         // we reset the state, calculate water
//         int state = 0;
//         vector<int> tmp;
//         tmp.push_back(prev);
//         for (int i = 1; i < height.size(); i++) {

//             if (state == 0) {
//                 // start decreasing
//                 if (height[i] < prev)
//                     state = 1;
//             } else if (state == 1) {
//                 // start increasing
//                 if (height[i] > prev) {
//                     state = 2;
//                 }
//             } else {
//                 // start decreasing again, we have a section
//                 if (height[i] < prev) {
//                     ans += calculateWater(tmp);
//                     tmp = vector<int>();
//                     tmp.push_back(prev);
//                     state = 0;
//                 }

//             }

//             tmp.push_back(height[i]);
//             prev = height[i];
//         }


//         // [0,1,0,2,1,0,1,3,2,1,2,1]
//         // tmp = [0, 1, 0, 2, 1]


//         return ans;

//     }
// };


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.empty()) return 0;
//         int ans = 0;
//         int size = height.size();
//         vector<int> left_max(size), right_max(size);
//         left_max[0] = height[0];
//         for (int i = 1; i < size; i++) {
//             left_max[i] = max(height[i], left_max[i - 1]);
//         }
//         right_max[size - 1] = height[size - 1];
//         for (int i = size - 2; i >= 0; i--) {
//             right_max[i] = max(height[i], right_max[i + 1]);
//         }
//         for (int i = 1; i < size - 1; i++) {
//             ans += min(left_max[i], right_max[i]) - height[i];
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0, current = 0;

        // st stores the 
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int bottom_idx = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height =
                    min(height[current], height[st.top()]) - height[bottom_idx];

                ans += distance * bounded_height;
            }
            st.push(current++);

        }
        return ans;

    }
};
