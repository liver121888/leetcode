/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// we can have a fast and slow pointer
// if no cycle, fast pointer will reach null
// if has cycle we break when fast == slow
// start from the head again
// traverse at same speed
// the ans will be the ponint they meet again

// 3 2 0 -4
// 3 3
// 2 0
// 0 2
// -4 -4
// cycle
// 3 -4
// 2 2
// 2 is the entry point
// why?

// traverse a
// still has b
// 2(c+a) = c + a + b + a
// 2c + 2a = c + 2a + b
// c = c + b

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (!head || !head->next)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        bool hasCycle = false;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle)
            return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
        
    }
};