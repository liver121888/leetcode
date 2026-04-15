
// there might be repeated words
// we can traverse the array and 
// count the minimum target in both ways

// ["hello","i","am","leetcode","hello"]
// startIndex = 1
// [0 1 2 3 4] [5 6 7 8 9]
// 1 4 3 2

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        
        if (words[startIndex] == target)
            return 0;
        int n = words.size();
        int minDist = n;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                // if (i > startIndex) {
                //     minDist = min(i - startIndex, minDist);
                //     minDist = min(startIndex + n - i, minDist);
                // } else {
                //     minDist = min(startIndex - i, minDist);
                //     minDist = min(i + n - startIndex,minDist);
                // }
                int dist = abs(i - startIndex);
                minDist = min(minDist, min(dist, n - dist));
            }
        }
        return minDist == n ? -1 : minDist;
    }
};