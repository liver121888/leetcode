/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// height balanced
// should find the middle of the list every time
// either center should be fine
// zero node
// one node
// two nodes
// 3 -> center

// after finding the center
// recursion to find the center 
// we also need the prev pointer to cut the list

// pair<node,node> split(list)
// root -> left = helper(root, frontList)
// root -> right = helper(root, backList)
// return root


// Approach 3: Inorder Simulation
// O(n)
// O(logn)
class Solution {
public:
    ListNode* head;
    int findSize(ListNode* head) {
        ListNode* ptr = head;
        int c = 0;
        while (ptr != NULL) {
            ptr = ptr->next;
            c += 1;
        }
        return c;
    }
    TreeNode* convertListToBST(int l, int r) {
        // Invalid case
        if (l > r) {
            return NULL;
        }
        int mid = (l + r) / 2;
        // First step of simulated inorder traversal. Recursively form
        // the left half
        TreeNode* left = this->convertListToBST(l, mid - 1);
        // Once left half is traversed, process the current node
        TreeNode* node = new TreeNode(this->head->val);
        node->left = left;
        // Maintain the invariance mentioned in the algorithm
        this->head = this->head->next;
        // Recurse on the right hand side and form BST out of them
        node->right = this->convertListToBST(mid + 1, r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // Get the size of the linked list first
        int size = this->findSize(head);
        this->head = head;
        // Form the BST now that we know the size
        return convertListToBST(0, size - 1);
    }
};



// O(nlogn)
// O(logn)
// class Solution {
// public:
//     pair<ListNode*, ListNode*> split(ListNode* head) {
//         if (!head) return {nullptr, nullptr};

//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = nullptr;

//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // slow is middle node
//         if (prev) {
//             prev->next = nullptr; // cut left list
//         }

//         // return leftHead and middle node
//         if (slow == head) {
//             return {nullptr, slow};
//         }

//         return {head, slow};
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         if (!head) return nullptr;

//         auto [leftHead, mid] = split(head);

//         ListNode* rightHead = mid->next;
//         // cut mid and right
//         mid->next = nullptr;

//         TreeNode* root = new TreeNode(mid->val);
//         root->left = sortedListToBST(leftHead);
//         root->right = sortedListToBST(rightHead);

//         return root;
//     }
// };

// class Solution {
// public:

//     pair<ListNode*, ListNode*> split(ListNode* head) {
        
//         if (!head)
//             return {nullptr, nullptr};

//         // find the middle and middle prev
//         ListNode* fast = head;
//         ListNode* slow = head;
//         ListNode* prev;
//         while (fast && fast->next) {
//             fast = fast->next->next;
//             prev = slow; 
//             slow = slow->next;
//         }
//         // break the chain
//         if (head == slow)
//             return {nullptr, slow};
//         prev->next = nullptr;
//         return {head, slow};
//     }

//     // []
//     // [10]
//     // [10, 12]
//     // [10, 12, 11]
//     // [-10 -3 0 5 9]

//     TreeNode* sortedListToBST(ListNode* head) {

//         if (!head)
//             return nullptr;

//         auto [firstList, secondList] = split(head);

//         TreeNode* root = new TreeNode(secondList->val);
//         // cout << root->val << endl;

//         root->left = sortedListToBST(firstList);
//         root->right = sortedListToBST(secondList->next);
        
//         return root;
//     }
// };
