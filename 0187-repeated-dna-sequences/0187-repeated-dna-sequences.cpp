class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        if(s.length() <= 10) { 
            return {};
        }        
        
        vector<string> ans;
        unordered_map<string,int> hash;    

        for (int l = 0; l < s.length() - 9; l++) {
            string cur = s.substr(l, 10);
            hash[cur]++;
            if(hash[cur] == 2){
                ans.push_back(cur);
            }
        }
        return ans;
    }
};