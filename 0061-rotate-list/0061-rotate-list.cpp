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

// we need to find the new head
// also find the new tail
// so that we can connect the old head to the new tail
// we get the size of the list first, n
// k % n to get how many times we need to rotate
// rotate k means the new head would be the  k element cnt from the back

// O(n) to find the len of the list
// find the tail too
// k % n so we know the new head
// n-k and we traverse the list
// take the new head as the head, connect tail to the old head
// return new head

// nullptr for the head
// or just a single node
// k might = 0
// return head

// time: O(n)
// space: O(1)

class Solution {
public:

    // 1 2 3 4 5 k = 2
    // n = 5, tail = 5, k = 2
    // k = 2
    // cnt = 3
    // newHead is 4 and prev is 3
    // 0 1 2 k = 4
    // [] k = 1
    // 1 k = 10 -> 1
    // 1 2 k = 1
    // tail = 2, k = 1
    // prev = 1, newHead = 2
    // 1 2 k = 0

    ListNode* rotateRight(ListNode* head, int k) {

        // edge cases
        if (!head || !head->next || k == 0)
            return head;

        // find the size of the list
        int n = 1;
        ListNode* tail = head;
        // 0 -> 1, so our len is correct and we stop at the tail
        while (tail->next) {
            n++;
            tail = tail->next;
        }

        // so we don't rotate too many times
        k = k % n;

        if (k == 0)
            return head;
        
        int cnt = n - k;
        // count to find the kth node from the back
        ListNode* newHead = head;
        ListNode* prev = nullptr;

        // cnt = 2;
        // prev = 1
        // newHead = 2
        //cnt = 1
        // prev = 2
        // newHead = nullptr

        while (cnt) {
            prev = newHead;
            newHead = newHead->next;
            cnt--;
        }

        // break the link
        prev->next = nullptr;
        tail->next = head;
        return newHead;
    }
};