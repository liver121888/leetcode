class Solution {
public:

    vector<pair<int, char>> encode(string s) {
        
        vector<pair<int, char>> result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '_')
                result.emplace_back(i, s[i]);
        }
        return result;
    }

    bool canChange(string start, string target) {

        // two pointers
        vector<pair<int, char>> startCode = encode(start);
        vector<pair<int, char>> targetCode = encode(target);

        if (startCode.size() != targetCode.size())
            return false;

        for (int i = 0; i < startCode.size(); i++) {
            const auto& [startId, startChar] = startCode[i];
            const auto& [targetId, targetChar] = targetCode[i];

            if (startChar != targetChar)
                return false;

            if (startChar == 'R') {
                if (targetId < startId)
                    return false;
            } else {
               if (targetId > startId)
                    return false;
            }
        }

        return true;
    }
};