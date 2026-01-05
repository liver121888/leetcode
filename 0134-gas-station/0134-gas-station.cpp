// we need to find a index that
// 1. from that index we traverse the both array, accumulate gas[i] >= accumulate cost[i]
// 2. this index needs to have gas[i] >= cost[i]

// we can simulate the whole process at every possible index
// time: O(n^2)
// space: O(1)

// 1 2 3 4 5 gas
// 3 4 5 1 2 cost

// we can use prefix sum calculate range sum quickly
// 1 3 6 10 15
// 3 7 12 13 15

// let's say we found two candidates from the example, index 3 and 4
// we start from index 3, we need range sum from 3-4 and 0-2
// prefix[n-1] - prefix[i-1] = prefix[4] - prefix[2] = 15 - 6 = 9
// 15 - 12 = 3
// prefix[2] - prefix[0-1] = 6
// 12 
// 9 + 6 = 15
// 3 + 12 = 15
// so it's possible

// no this is WRONG!
// we might die in the mid way

// time: O(n)
// space: O(1)


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int currGain = 0, totalGain = 0, answer = 0;

        for (int i = 0; i < gas.size(); ++i) {
            // gain[i] = gas[i] - cost[i]
            totalGain += gas[i] - cost[i];
            currGain += gas[i] - cost[i];

            // If we meet a "valley", start over from the next station
            // with 0 initial gas.
            if (currGain < 0) {
                answer = i + 1;
                currGain = 0;
            }
        }

        return totalGain >= 0 ? answer : -1;

    }
};