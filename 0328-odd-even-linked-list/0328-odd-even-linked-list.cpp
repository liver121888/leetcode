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

// Given the head of a singly linked list, group all the nodes with odd indices together 
// followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// odd list and even list
// we concatenate them tgt

// two pointers, one is on the odd and the other is on the even
// we find the next two pointers and we move our pointers there
// before that, we broke the connection from the odd and even

// oddhead, oddcurr
// evenhead, evencurr
// prev
// oddnext, evennext

// we progress the curr to the next
// we check if the curr exist,
// if it exist, we connect prev->next to curr
// one of the pointers become null
// we connect the pointers 
// oddprev -> evenhead

// while (oddcurr || evencurr) {
    // take the next
    // connect prev to curr
    // progress to next
// }

// check if oddstill has then we need to connect the odd to curr
// connect two lists

class Solution {
public:

    // []
    // [1]
    // [1 2]

    // head 1 curr 1
    // evenHead = 2
    // NEXTCURR =  null
    // even = 2
    // 1 -> null
    // prev = 1
    // curr = null
    // 1 2 

    // [1 2 3]
    // head 1 curr 1
    // evenHead = 2
    // NEXTCURR =  3
    // even = 2
    // 1 -> null
    // 2->null
    // prev = 1
    // curr = 3
    // 1->3->2


    // [1,2,3,4] 
    // head 1 curr 1
    // evenHead = 2
    // NEXTCURR =  3
    // even = 2
    // 1 -> 3
    // 2-> 4
    // prev 1
    // curr 3

    // null
    //     2->4
    //     1 -> 3 -> null

    // prev = 3


    // way cleaner version
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next) 
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }


    // ListNode* oddEvenList(ListNode* head) {
        
    //     if (!head || !head->next)
    //         return head;

    //     ListNode* evenHead = head->next;
    //     ListNode* curr = head;
    //     ListNode* prev = nullptr;
    //     while (curr && curr->next) {
    //         ListNode* nextCurr = curr->next->next;
    //         ListNode* even = curr->next;
    //         curr->next = nextCurr;
    //         if (nextCurr)
    //             even->next = nextCurr->next;
    //         prev = curr;
    //         curr = nextCurr;
    //     }

    //     if (curr) {
    //         prev->next = curr;
    //         prev = curr;
    //     }

    //     prev->next = evenHead;
    //     return head;
    // }
};