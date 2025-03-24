class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        // [[1,3], [2, 4], [5,7], [9,10]]

        // case 1: no overlap
        
        // case 2: overlap

        // 10, [[5,7],[1,3],[9,10]]
        // 10, [[1,3], [5,7],[9,10]]
        // result = 2

        // days = 5, meetings = [[2,4],[1,3]]
        // [1, 3], [2 ,4]

        // days = 6, meetings = [[1,6]]
        // n = 1 -> no loop
        // 1 - 1
        // 6 -6 
        // result = 0

        // 57, [[3,49],[23,44],[21,56],[26,55],[23,52],[2,9],[1,48],[3,31]]
        // [[1,48],[2,9],[3,31],[3,49],[21,56], [23,44],[23,52],[26,55]]
        
        int n = meetings.size();
        int result = 0;
        int latestEnd = 0;

        for (int i = 0; i < n; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if (start > latestEnd + 1) {
                result += start - latestEnd - 1;
            }

            latestEnd = max(latestEnd, end);
        }

        // the last meeting
        result += days - latestEnd;
        return result;
    }
};