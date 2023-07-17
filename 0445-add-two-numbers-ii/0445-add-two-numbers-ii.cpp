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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);
        int carry {0};
        int sum {0};
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            if (sum >= 10) {
                carry = 1;
                cur->next = new ListNode(sum - 10);
            } else {
                carry = 0;
                cur->next = new ListNode(sum);
            }        
            cur = cur->next;
        }
        if (carry != 0) {
            cur->next = new ListNode(1);
        }
        return reverseLinkedList(ans->next);
    }
    
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr  || head->next == nullptr ) {
            return head;
        }        
        ListNode* reversedHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedHead;
    }
    
};