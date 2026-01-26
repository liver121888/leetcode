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

// we can easily do a two pass solution
// calculate the size then progress that much and remove the n^th node


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        // if (!head->next)
        //     return nullptr;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        // we can have an array of all the pointer in the linked list
        // and when we reach the end we know which one to remove
        vector<ListNode*> ptrs;
        
        while (curr) {
            ListNode* ptr = curr;
            // store it in the 
            ptrs.push_back(ptr);
            curr = curr->next;
        }

        // [0 1 2]

        ptrs[ptrs.size() - n - 1]->next = ptrs[ptrs.size() - n]->next;
        return dummy->next;
    }
};