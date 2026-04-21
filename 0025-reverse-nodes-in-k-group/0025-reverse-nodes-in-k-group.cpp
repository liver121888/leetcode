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

// Follow-up: Can you solve the problem in O(1) extra memory space?
// reverse nodes in k groups

// invariant: we need a function to reverse linkedlist
// after reversal, return the first and the last node
// we connect it back

class Solution {
public:

    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }
    //     ListNode* p = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return p;
    // }

    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* new_head = nullptr;
        ListNode* ptr = head;
        while (k > 0) {
            ListNode* next_node = ptr->next;
            ptr->next = new_head;
            new_head = ptr;
            ptr = next_node;
            k--;
        }
        return new_head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;
        while (count < k && ptr != nullptr) {
            ptr = ptr->next;
            count++;
        }
        if (count == k) {
            ListNode* reversedHead = this->reverseLinkedList(head, k);
            head->next = this->reverseKGroup(ptr, k);
            return reversedHead;
        }
        return head;
    }

    
};