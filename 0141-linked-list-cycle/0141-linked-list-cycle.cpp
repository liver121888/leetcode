// we can solve using one pointer and hash_set
// if we encoounter the same node, we know we 
// have a cycle
// we can do fast slow ptr


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
    bool hasCycle(ListNode *head) {

        // The number of the nodes in the list is in the range [0, 104].
        if (!head)
            return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next && slow) {

            fast = fast->next->next;
            slow = slow->next;

            // we check after we move
            if (fast == slow)
                return true;

        }
        return false;
    }
};