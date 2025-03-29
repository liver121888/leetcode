class Solution {
public:
    int shortestWay(string source, string target) {

        // find the minimum time that source need to repeat so that it can gen target
        // counting

        // abc acdbc -> -1
        // counting

        vector<int> sourceCnts(26);

        for (auto c : source) {
            sourceCnts[c - 'a']++;
        }

        int j = 0;
        int result = 1;
        for (int i = 0; i < target.length(); i++) {
            auto currC = target[i];

            if (sourceCnts[currC - 'a'] == 0)
                return -1;

            // find next match
            while (currC != source[j] && j < source.length()) {
                j++;
            }

            // if we deplete source 
            if (j == source.length()) {
                // reset j and concatenate a new source
                j = 0;
                result += 1;
                // will gurantee find a result
                while (currC != source[j]) {
                    j++;
                }
            }
            // increment j becaues we found a match
            j++;
            // move to next target c by increment i
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