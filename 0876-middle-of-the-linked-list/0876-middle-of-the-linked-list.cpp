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

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]

// we can have a fast pointer
// a slow pointer

// The number of nodes in the list is in the range [1, 100].


class Solution {
public:

    // Input: head = [1,2,3,4,5]
    // Output: [3,4,5]

    // Input: head = [1,2,3,4,5,6]
    // Output: [4,5,6]

    // Input: head = [1]
    // Output: [1]

    // Input: head = [1,2]
    // Output: [2]

    ListNode* middleNode(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};