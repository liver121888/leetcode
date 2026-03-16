class Solution {
public:

    // space O(1) method
    bool canChange(string start, string target) {

        int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        // 這種不定長度的
        // 外圈永遠放個or
        // 然後再到內圈看
        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }


    // vector<pair<int, char>> encode(string s) {
        
    //     vector<pair<int, char>> result;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] != '_')
    //             result.emplace_back(i, s[i]);
    //     }
    //     return result;
    // }

    // bool canChange(string start, string target) {

    //     // two pointers
    //     vector<pair<int, char>> startCode = encode(start);
    //     vector<pair<int, char>> targetCode = encode(target);

    //     if (startCode.size() != targetCode.size())
    //         return false;

    //     for (int i = 0; i < startCode.size(); i++) {
    //         const auto& [startId, startChar] = startCode[i];
    //         const auto& [targetId, targetChar] = targetCode[i];

    //         if (startChar != targetChar)
    //             return false;

    //         if (startChar == 'R') {
    //             if (targetId < startId)
    //                 return false;
    //         } else {
    //            if (targetId > startId)
    //                 return false;
    //         }
    //     }
    //     return true;
    // }

};