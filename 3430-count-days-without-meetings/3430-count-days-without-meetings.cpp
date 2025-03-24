class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping intervals
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);

        for (int i = 1; i < meetings.size(); ++i) {
            vector<int>& last = merged.back();
            if (meetings[i][0] <= last[1]) {
                // Overlap: extend the last interval
                last[1] = max(last[1], meetings[i][1]);
            } else {
                // No overlap: add new interval
                merged.push_back(meetings[i]);
            }
        }

        // Step 3: Count free days
        int busyDays = 0;
        for (const auto& interval : merged) {
            busyDays += interval[1] - interval[0] + 1;
        }

        return days - busyDays;
    }
};
