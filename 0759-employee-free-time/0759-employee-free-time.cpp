/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

// we are given the working time of each employee
// we need to find common free time
// the employee's free time is in sorted order
// we can process one by one
// initial -> -inf to inf
// first -> we block certain parts
// second -> we block another certain parts
// we remove the interval that -inf or inf
// instead of doing this, we can union the work time
// and take inverse in the end
// [1, 2], [5, 6]
// [1, 3] -> we binary serach and take the union
// what if [1, 2], [7, 9], then we have [4, 10]?
// we still binary serach -> check overlap, then take min(a, b), max(a, b)
// binay serach n times-> O(nlogn)


class Solution {
public:


    // [1, 3] [6, 9]
    // [1, 6]

    // 1 3
    // 2

    // helper(vector<Interval>& ans, Interval time) {

    //     if (ans.empty()) {
    //         ans.push_back(time);
    //     }

    //     int l = 0, r = ans.size() - 1;

    //     while (l <= r) {
    //         int mid = l + (l - r) / 2;
    //         if (ans[mid].start < time.start) {
    //             l  = mid + 1;
    //         } else {
    //             r = mid - 1;
    //         }
    //     }
        
    //     // we find the position at r
    //     if (checkOverlapo(ans[r], time)) {
    //         // if overlap we union
    //     } else {

    //     }

    // }


    // if equal, eg [1, 5], [5, 10]
    // we consider no free time
    // so we return true, means we have overlap
    // bool checkOverlap(Interval a, Interval b) {
    //     return max(a.start, b.start) <= min(a.end, b.end);
    // }

    // If some interval overlaps any interval (for any employee), then it won't be included 
    // in the answer. So we could reduce our problem to the following: 
    // given a set of intervals, find all places where there are no intervals.

    // Merge interval in place
    int merge(vector<Interval>& input) {
        // 用 w 表示「合併結果目前寫到哪」

        // w 指向「目前最後一個合併好的區間」

        // i 是掃描指標，從第二個區間開始往右看

        // 流程（概念）：

        // 初始化：w = 0

        // 代表目前合併結果只有第 0 個 interval（直接用它當起點）

        // 從 i = 1 掃到最後：

        // 若 interval[i].start <= interval[w].end：
        // 代表跟最後合併段有重疊 → 把 interval[w].end 擴張

        // 否則（interval[i].start > interval[w].end）：
        // 代表出現新的不重疊段 → w++，然後把 interval[i] 搬到 interval[w]

        // 這步就是「壓縮」：把新的段寫到前面來

        int n = input.size();
        int l = 0;
        int r = 1;
        while (r < n) {

            if (input[r].start <= input[l].end) {
                // merge
                input[l].end = max(input[l].end, input[r].end);

            } else {
                // no overlap
                l++;
                input[l] = input[r];
            }
            r++;
        }
        return l+1;
    }

    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        vector<Interval> result;

        for (const auto& v : schedule) {
            for (const auto& interval : v) {
                result.push_back(interval);
            }
        }

        sort(result.begin(), result.end(), [](const Interval& a, const Interval& b) {
            if (a.start < b.start) {
                return true;
            } else if (a.start > b.start) {
                return false;
            } else {
                if (a.end < b.end) {
                    return true;
                } else {
                    return false;
                }
            }
        });

        // cout << "result: ";
        // for (const auto& r : result){
        //     cout << "[" << r.start << "," << r.end << "]";
        // }
        // cout << "]" << endl;

        int resultSize =  merge(result);

        // cout << resultSize << endl;

        // cout << "result: ";
        // for (const auto& r : result){
        //     cout << "[" << r.start << "," << r.end << "]";
        // }
        // cout << "]" << endl;


        vector<Interval> ans;

        for (int i = 0; i < resultSize-1; i++) {
            ans.emplace_back(result[i].end, result[i+1].start);
        }

        return ans;
    }
};