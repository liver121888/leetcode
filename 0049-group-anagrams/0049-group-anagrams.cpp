class Solution {
public:
    
    bool myCmp (string i,string j) { 
        return (i.length()<j.length()); 
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans; 
        unordered_map<string,vector<string>> umap; 
        for(auto x:strs){
            string temp=x; 
            sort(x.begin(),x.end()); 
            umap[x].push_back(temp); 
        } 
        for(auto x:umap){
            // vector<string> tmp=x.second; 
            // ans.push_back(tmp); 
            ans.push_back(x.second); 
        }
        return ans; 
    }
};