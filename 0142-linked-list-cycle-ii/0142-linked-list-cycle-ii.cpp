/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:


    // 3 2 0 -4
    // slow -4
    // fast -4

    // slow 3
    // fast -4
    // fast 2
    // slow 2
    // return fast

    // 1 2
    // slow 1
    // fast 1
    // slow 2
    // fast 1

    // slow 1
    // fast 1
    
    // slow
    // fast

    

    ListNode *detectCycle(ListNode *head) {

        ListNode* fast = head;
        ListNode* slow = head;

        bool hasCycle = false;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            // we check after we move
            // otherwise we won't even start the algo
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle)
            return nullptr;

        // fast will be the intersection point
        // we start the fast as slow and let the slow 
        // has time to catch up

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};