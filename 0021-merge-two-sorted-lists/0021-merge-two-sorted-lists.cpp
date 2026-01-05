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
class Solution {
public:

    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //     ListNode* start1 = list1;
    //     ListNode* start2 = list2;

    //     if (!start1) return start2;
    //     if (!start2) return start1;

    //     ListNode* head;
    //     ListNode* first_head;

    //     if (start1->val < start2->val) {
    //         head = start1;
    //         first_head = start1;
    //         start1 = start1->next;
    //     } else {
    //         head = start2;
    //         first_head = start2;
    //         start2 = start2->next;
    //     }

    //     while (start1 && start2) {
    //         if (start1->val < start2->val) {
    //             first_head->next = start1;
    //             start1 = start1->next;
    //         } else {
    //             first_head->next = start2;
    //             start2 = start2->next;
    //         }
    //         first_head = first_head->next;
    //     }

    //     if (start1) {
    //         first_head->next = start1;
    //     } else {
    //         first_head->next = start2;
    //     }

    //     return head;
    // }

    // both list are already sorted
    // we can always compare the current node and link the smaller one
    // after the operations we might left with a part, append that part
    // time complexity: O(n)
    // space complexity: O(1)
    // some special case: empty list

    // I will do my solution here
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        // list1 = [1,2,4], list2 = [1,3,4]
        
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                // connect main list to list1
                dummy->next = list1;
                // advance list1 ptr
                list1 = list1->next;
                // disconnect main list from list1
                dummy->next->next = nullptr;
            } else {
                // connect main list to list2
                dummy->next = list2;
                // advance list2 ptr
                list2 = list2->next;
                // disconnect main list from list2
                dummy->next->next = nullptr;
            }
            
            // progress the main list
            dummy = dummy->next;
        } 
        
        if (list1) {
            dummy->next = list1;            
        }
        
        if (list2) {
            dummy->next = list2;            
        }

        return head->next;
        
    }
};
