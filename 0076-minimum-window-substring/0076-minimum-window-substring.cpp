#define MAP_SIZE 60 //(65-90) + (97-122), ASCII

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> cnts(MAP_SIZE, 0);
        vector<int> windowCnts(MAP_SIZE, 0);;
        int ansLeft = 0;
        int ansRight = 1e6;
        
        for (auto c : t)
            cnts[c - 'A']++;
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            windowCnts[s[right] - 'A']++;
            
            // contract left
            while (left <= right && checkValid(cnts, windowCnts) == true) {
                if (right - left + 1 < ansRight - ansLeft + 1) {
                    ansLeft = left;
                    ansRight = right;
                }

                windowCnts[s[left] - 'A']--;
                left++;
            }

        }
        
        if (ansRight - ansLeft == 1e6)
            return "";
        
        return s.substr(ansLeft, ansRight - ansLeft + 1);
    }

    bool checkValid(vector<int>& cnts, vector<int>& windowCnts)
    {
       for(int i=0; i < MAP_SIZE; i++)
       {
           if(windowCnts[i] < cnts[i])
               return false;               
       }
        return true;
    }

};