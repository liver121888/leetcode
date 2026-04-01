/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

// [1,2,3,null,4]

//  1
// 2  3
//  4

class Solution {
public:


    // Node* LCA(Node* root, Node* p, Node* q) {

    //     if (!root)
    //         return nullptr;
        
    //     if (root == p || root == q)
    //         return root;

    //     Node* left = LCA(root->left, p, q);
    //     Node* right = LCA(root->right, p, q);
        
    //     if (left && right)
    //         return root;

    //     return left ? left : right;

    // }

    Node* lowestCommonAncestor(Node* p, Node * q) {

        // view it has graph problem
        // start with node p, go all the way to parents
        // start with node q, go all the way to parents
        // if they meet at certain point
        // return that
        // other wise nullptr
        // we can save it as vector to know the path

        // or simply find the root then call LCA
        // to have O(1) space
        // method 1
        // if (!p || !q)
        //     return nullptr;

        // Node* curr = p;
        // while (curr && curr->parent) {
        //     curr = curr->parent;
        // }
        // return LCA(curr, p, q);


        // This solution is mind blowing. The idea is this say p to root is path length 
        // is a + c and q to root path length is b + c where c is the length of the common 
        // path to root after they meet. Then we are just making them both travel the same 
        // distance a + b + c by this swapping when root trick. So they exactly meet at that 
        // common merging point which is the LCA.
        Node* p1 = p, *p2 = q;
        while (p1 != p2) {
            p1 = p1->parent ? p1->parent : q;
            p2 = p2->parent ? p2->parent : p;
        }

        return p1;
        
    }
};