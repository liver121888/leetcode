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

// Let's define a as the length of the path from the start of the list to the entrance of the cycle.
// Let's define b as the length of the path from the cycle's entrance to the meeting point of the hare 
// and the tortoise inside the cycle.
// Let's define c as the total length of the cycle.
// a + b = k * c
// fast may have walk the cycle a lot of time
// 2 * (a + b) = a + b + k*c
// k * c = a + b
// so when we start frome the head
// hare now has a distance to travel to the entrance of the cycle
// rearrange to get a = k*c - b
// let's say we walk the turtle k*c - b steps
// relative to the cycle entrace will be 
// (k*c - b) + b = k*c = the entrance
// so we find the entrance

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