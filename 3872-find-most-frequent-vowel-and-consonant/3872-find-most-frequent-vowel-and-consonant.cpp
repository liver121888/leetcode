class Solution {
public:
    int maxFreqSum(string s) {

        vector<int> freq(26);
        unordered_set<int> vowels = {0, 4, 8, 14, 20};

        for (auto c : s) {
            freq[c - 'a']++;
        }

        int maxVFreq = 0;
        for (auto it = vowels.begin(); it != vowels.end(); it++) {
            maxVFreq = max(freq[*it], maxVFreq);
        }

        int maxCFreq = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (vowels.find(i) == vowels.end()) {
                maxCFreq = max(freq[i], maxCFreq);
            }
        }
        cout << "maxVFreq: " << maxVFreq << ", maxCFreq: " << maxCFreq << endl;
        return maxVFreq + maxCFreq;
        
    }
};