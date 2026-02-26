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

// Follow up: Could you do it in O(n) time and O(1) space?
// how to check palindrome
// we can build a vector then check both ends
// O(n) space, O(n) time

// we can go to the end first
// size of the linkedlist
// fidn the middle of the linkedlist first
// we reverse the linked list of the second half
// we traverse two linked list

// 1 -> 2 -> 2 -> 1
// slow 2nd 2
// 1->2
// prevPtr to reverse the linked list
// <- 2 <- 1
// and then we traverse from 1 to see if it matches

// 3 pointers
// fast, slow, prev

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (head && !head->next)
            return true;

        // find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // cout << prev->val << " " << slow->val << endl;

        // break the list
        prev->next = nullptr;
        prev = nullptr;

        // reverse the linkedlist from slow
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // reuse fast ptr
        fast = head;
        // traverse both list
        // slow list will have one more node maybe
        while (fast) {
            if (fast->val != prev->val)
                return false;
            fast = fast->next;
            prev = prev->next;
        }

        return true;
    }
};