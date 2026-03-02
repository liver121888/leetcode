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

// 2 4 3
// 342
// 5 6 4
// 465

// 342+465 = 807

// 7 -> 0 -> 8

// l1 = [0], l2 = [0]
// 0

// l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// [8,9,9,9,0,0,0,1]

// two pass: O(n)
// space: O(n)


// two pass: the first pass to find the longer one
// second pass: sum on the longer one, and attach one more node if needed 
// O(1) space

// [2,4,9]
// [5,6,4,9]

// l1Len
// 7 0 4 0 1

class Solution {
public:

    // each linked list is in the range [1, 100].
    int getLen(ListNode* l) {
        int result = 0;
        while (l) {
            result++;
            l = l->next;
        }
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int l1Len = getLen(l1);
        int l2Len = getLen(l2);

        ListNode* head = l1Len >= l2Len ? l1 : l2;
        ListNode* takePtr = head == l1 ? l2 : l1;
        int totalLen = head == l1 ? l1Len : l2Len;

        int carry = 0;
        ListNode* curr = head;
        while (totalLen) {
            int currVal = curr->val;
            if (takePtr) {
                currVal += takePtr->val;
                takePtr = takePtr->next;
            }
            currVal += carry;
            // cout << currVal << " " << l1Len << endl; 
            // 14 1
            // 1 4
            carry = currVal / 10;
            curr->val = currVal % 10;
            totalLen--;
            // deal with when we need to append a last node
            if (totalLen == 0) {
                if (carry) {
                    curr->next = new ListNode(carry);
                }
            }
            curr = curr->next;
        }

        return head;
    }
};