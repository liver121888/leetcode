/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// we can use bfs to traverse
// time: O(n)
// space: O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        vector<vector<int>> ans;

        if (!root)
            return ans;

        queue<Node*> bfs;
        bfs.push(root);
        while (!bfs.empty()) {

            int currLayerSize = bfs.size();
            vector<int> currLayer;
            while(currLayerSize) {
                Node* curr = bfs.front();
                bfs.pop();

                currLayer.push_back(curr->val);

                for (const auto& child : curr->children) {
                    bfs.push(child);
                }
                currLayerSize--;
            }
            ans.push_back(currLayer);

        }
        return ans;
    }
};