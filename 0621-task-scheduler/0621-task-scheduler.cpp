
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// 2 intervals as gap
// 8 intervals
//  A -> B -> idle -> A -> B -> idle -> A -> B

// tasks = ["A","C","A","B","D","B"], n = 1
// A -> B -> C -> D -> A -> B

// ["A","A","A", "B","B","B"], n = 3
// A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

// the sequence of tasks is not important here
// freq
// A B C D - Z
// 3 3 0 0   0
// n = 3

// invariant here
// t is invariant and will be our ans
// {0, A}, {1, B}
// we can use a for loop to simulate the interval process
// for each interval, we take one task and

// the last time we pushed in an A
// the last time we pushed in an B

// for every t
// we take a look at the remaining tasks
// and see the last time we pushed a certain task
// when it's > n we know we can process another

// A B C
// 8 1 7

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // count freq of tasks
        vector<int> freq(26);
        for (const auto& task : tasks) {
            freq[task - 'A']++;
        }
        // the lens is actually binded by the most freq element
        // we can return the size of vector
        // we not necessary need to build this
        // // A B C D E
        // // 5 1 3 4 2 n = 2
        // [A, B, C, A, D, C, A, D, C A, D, C, A, D, E]
        // [A, B, C, A, D, C, A, D, C A, D, C, A, D, E]


        // For every cycle, find the most frequent letter that can be 
        // placed in this cycle. 
        // After placing, decrease the frequency of that letter by one.

        // Sort the frequency array in non-decreasing order
        sort(freq.begin(), freq.end());

        // Time complexity: O(N)

        // The time complexity of the algorithm is O(26log26+N), 
        // where 26log26 is the time complexity of sorting the frequency array, 
        // and N is the length of the input task list, which is the dominating term.

        // Calculate the maximum frequency of any task
        // 最多頻率 task 之間有幾個 gap / block
        int maxBlocks = freq[25] - 1;
        
        // Calculate the number of idle slots that will be required
        int idleSlots = maxBlocks * n;

        // Iterate over the frequency array from the second highest frequency to the lowest frequency
        for (int i = 24; i >= 0 && freq[i] > 0; i--) {
            // Subtract the minimum of the maximum frequency and the current frequency from the idle slots
            // 意思是每一種其他 task 最多只能填進這些 gap 裡面一次。
            idleSlots -= min(maxBlocks, freq[i]);
        }

        // If there are any idle slots left, add them to the total number of tasks
        // If there are more tasks than slots left, return the task size
        // idleSlots > 0 代表還需要補 idle, so return idleSlots + tasks.size()
        // idleSlots <= 0 代表 task 本身夠多，沒有 idle，答案就是 task 數量。
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};