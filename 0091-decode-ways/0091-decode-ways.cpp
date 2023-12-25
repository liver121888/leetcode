class Solution {
    vector<int> store;
public:
    int numDecodings(string s) {
        int n = s.size();
        this->store = vector<int>(n, -1);
        long result = recursive(s, n, 0);
        if (result == INT_MAX) 
            return 0;

        return result;        
    }
    
    
    long recursive(string& s, int n, int p) {
        if (p >= n){
            return 1;
        }
        if (s[p] == '0'){
            return INT_MAX;
        }
        if (this->store[p] != -1){
            return this->store[p];
        } 
        
        //  regular case
        long sub, result = 0;
        sub = recursive(s, n, p + 1);
        if (sub < INT_MAX){
            result += sub;
        }
        if (p + 1 < n){
            int value = convert_str_to_int(s[p], s[p + 1]);
            if (value <= 26){
                sub = recursive(s, n, p + 2);    
                if (sub < INT_MAX){
                    result += sub;
                }
            }            
        }
        this->store[p] = result;
        return result;
    }
    
    int convert_str_to_int(char a, char b){
        return 10 * (a - '0') + b - '0';
    }
    
    
};