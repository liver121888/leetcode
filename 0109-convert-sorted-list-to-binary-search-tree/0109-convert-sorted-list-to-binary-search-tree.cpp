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

class Solution {
public:

    pair<ListNode*, ListNode*> split(ListNode* head) {
        
        if (!head)
            return {nullptr, nullptr};

        // find the middle and middle prev
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow; 
            slow = slow->next;
        }
        // break the chain
        if (head == slow)
            return {nullptr, slow};
        prev->next = nullptr;
        return {head, slow};
    }

    // []
    // [10]
    // [10, 12]
    // [10, 12, 11]
    // [-10 -3 0 5 9]

    TreeNode* sortedListToBST(ListNode* head) {

        if (!head)
            return nullptr;

        auto [firstList, secondList] = split(head);

        TreeNode* root = new TreeNode(secondList->val);
        // cout << root->val << endl;

        root->left = sortedListToBST(firstList);
        root->right = sortedListToBST(secondList->next);
        
        return root;
    }
};