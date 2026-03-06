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

// we can do k times
// we can get the len first
// so we know where we need to cut
// we can use two pointers

// one pass to get the len
// len 5 2
// we take the last k and put it to the front
// what if len 3 k = 4
// we take the % 

// 4 % 3 = 1
// 2 -> 0 -> 1

// edge cases
// empty -> empty
// 1 node -> 1 node rotate 0 return head
// 2 nodes -> should be fine

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head)
            return head;

        ListNode* curr = head;
        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }

        int rotate = k % n;

        if (rotate == 0)
            return head;
        
        // get last rotate nodes
        ListNode* secondPart = head;
        ListNode* secondPartPrev;
        ListNode* prev;
        curr = head;
        while (rotate) {
            curr = curr->next;
            rotate--;
        }

        while(curr) {
            secondPartPrev = secondPart;
            prev = curr;
            curr = curr->next;
            secondPart = secondPart->next;
        }

        prev->next = head;
        head = secondPartPrev->next;
        secondPartPrev->next = nullptr;

        return head;
    }
};
