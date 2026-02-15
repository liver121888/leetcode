// O(nk), build sliding windows and take max everytime
// O(nlogn), we have a heap and swipe through, everytime we look at 
// the top, and record the pointer to pop
// O(n)? each step we add one and remove one

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < k; i++) {
            // this is to remain monotonic, pop all the things that is 
            // smaller than the current number
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};