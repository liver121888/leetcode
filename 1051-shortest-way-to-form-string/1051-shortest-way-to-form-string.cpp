class Solution {
public:
    int shortestWay(string source, string target) {

        // find the minimum time that source need to repeat so that it can gen target
        // counting

        // abc acdbc -> -1
        // counting

        vector<int> sourceCnts(26);
        vector<int> targetCnts(26);

        for (auto c : source) {
            sourceCnts[c - 'a']++;
        }
        // for (auto c : target) {
        //     targetCnts[c - 'a']++;
        // }

        // for (int i = 0; i < targetCnts.size(); i++) {
        //     if (targetCnts[i] != 0 && sourceCnts[i] == 0)
        //         return -1;
        // }

        int j = 0;
        int result = 1;
        for (int i = 0; i < target.length(); i++) {
            auto currC = target[i];

            if (sourceCnts[currC - 'a'] == 0)
                return -1;

            while (currC != source[j] && j < source.length()) {
                j++;
            }

            if (j == source.length()) {
                j = 0;
                result += 1;
                while (currC != source[j]) {
                    j++;
                }
            }
            // move to next target c by increment i
            j++;
        }

        // abc abcbc
        // i = 3, j = 0 -> result = 2
        // j = 2
        // c ? b

        // xyz xzyxz
        // xz -> y
        // 3

        // source.length = n
        // target.length = m

        // O(m*n)
        // O(1)

        return result;
        
    }
};