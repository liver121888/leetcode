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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        bool shouldSwap = false;
        while(head) {
            cout << head->val << " " << prev->val << " " << shouldSwap << endl;
            if (shouldSwap) {
                // swap value
                int tmp = head->val;
                head->val = prev->next->val;
                prev->next->val = tmp;
                // move prev
                prev = head;
            }

            head = head->next;
            shouldSwap = !shouldSwap;
        }

        // -1 1 2 3 4
        // prev = -1
        // head = 1
        // false

        // head = 2
        // prev = -1
        // true
        // -1 2 1 3 4

        // prev = 1
        // head = 3
        // false

        // prev = 1
        // head = 4
        // true
        // -1 2 1 4 3

        // res: 2 1 4 3

        // [] -> nullptr

        // [1] -> [1]

        return dummy->next;
    }
};