/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // root is guaranteed to exist
        unordered_map<int, unordered_set<int>> map;
        convertToGraph(root, 0, map);
        queue<int> bfs;
        bfs.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);
        while (!bfs.empty()) {
            int n = bfs.size();
            for (int i = 0; i < n; i++){
                int current = bfs.front();
                bfs.pop();
                for (int vertex : map[current]) {
                    if (visited.find(vertex) == visited.end()) {
                        visited.insert(vertex);
                        bfs.push(vertex);
                    }
                }
            }
            minute++;            
        }
        return minute - 1;                
    }
    
    void convertToGraph(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
        if (!current)
            return;
        if (map.find(current->val) == map.end()) {
            // not visited, create empty set
            map[current->val] = unordered_set<int>();
        }
        if (parent != 0)
            map[current->val].insert(parent);
        if (current->left)
            map[current->val].insert(current->left->val);
        if (current->right)
            map[current->val].insert(current->right->val);        
       convertToGraph(current->left, current->val, map);
       convertToGraph(current->right, current->val, map); 
    }    

    
};