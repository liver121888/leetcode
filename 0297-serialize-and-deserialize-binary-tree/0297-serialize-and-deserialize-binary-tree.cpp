/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// we are not necessary need to encode to string
// we just need a data that can hold -1000 to 1000 around 2000+1 values
// we know that 2^10 is 1024
// we can do a dfs and input impossible value for null nodes
// we can do the inorder we save them and just build the tree 
// encode
// space: n
// time: let depth be d, and number of node be n
// we inorder and preorder so O(2^d)

// decode
// build the tree from it O(2^d)

// how can prevent saving null?
// we can do inorder + preorder


class Codec {
public:
    void ser(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "null ";
            return;
        }
        out << root->val << ' ';
        ser(root->left, out);
        ser(root->right, out);
    }

    string serialize(TreeNode* root) {
        ostringstream out;
        ser(root, out);
        return out.str();
    }

    TreeNode* des(istringstream& in) {
        string token;
        if (!(in >> token)) return nullptr;      // no more data
        if (token == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = des(in);
        node->right = des(in);
        return node;
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return des(in);
    }
};



// class Codec {
// public:

//     string rserialize(TreeNode* root, string str) {
//         // Recursive serialization.
//         if (root == nullptr) {
//             str += "null,";
//         } else {
//             str += to_string(root->val) + ",";
//             str = rserialize(root->left, str);
//             str = rserialize(root->right, str);
//         }
//         return str;
//     }

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         return rserialize(root, "");
//     }

//     TreeNode* rdeserialize(const vector<string>& input, int& idx) {

//         if (input[idx] == "null")
//             return nullptr;

//         TreeNode* head = new TreeNode(stoi(input[idx]));
//         idx++;
//         head->left = rdeserialize(input, idx);
//         idx++;
//         head->right = rdeserialize(input, idx);

//         return head;
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         istringstream iss(data);
//         vector<string> out;
//         string token;

//         while (getline(iss, token, ',')) {
//             if (!token.empty())
//                 out.push_back(token);
//         }
//         int idx = 0;
//         return rdeserialize(out, idx);
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));