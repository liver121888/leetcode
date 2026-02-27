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

// you cannot modify the value

// [1,2,3,4]
// -1 -> 1 -> 2 -> 3 -> 4

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode dummy = ListNode();
        ListNode* dummyHead = &dummy;

        dummyHead->next = head;
        ListNode* nextHead = nullptr;
        ListNode* prev = dummyHead;

        // -1 -> 2 -> 1 -> 3
        while (head && head->next) {

            // swap head and head->next
            nextHead = head->next->next;
            prev->next = head->next;
            head->next->next = head;
            head->next = nextHead;
            prev = head;
            head = nextHead;
        }

        // we don't need this because we alreayd connect nextHead
        // if still node left
        // if (head)
        //     prev->next = head;

        return dummyHead->next;

    }


};



// in here you modify the value, so this is not the solution
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode(-1);
//         dummy->next = head;
//         ListNode* prev = dummy;
//         bool shouldSwap = false;
//         while(head) {
//             // cout << head->val << " " << prev->val << " " << shouldSwap << endl;
//             if (shouldSwap) {
//                 // swap value
//                 int tmp = head->val;
//                 head->val = prev->next->val;
//                 prev->next->val = tmp;
//                 // move prev
//                 prev = head;
//             }

//             head = head->next;
//             shouldSwap = !shouldSwap;
//         }

//         // -1 1 2 3 4
//         // prev = -1
//         // head = 1
//         // false

//         // head = 2
//         // prev = -1
//         // true
//         // -1 2 1 3 4

//         // prev = 1
//         // head = 3
//         // false

//         // prev = 1
//         // head = 4
//         // true
//         // -1 2 1 4 3

//         // res: 2 1 4 3

//         // [] -> nullptr

//         // [1] -> [1]

//         return dummy->next;
//     }
// };