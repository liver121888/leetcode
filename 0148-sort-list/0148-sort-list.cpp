
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// we can do a top down merge sort
// 4 2 1 3
// find mid and split
// 4 2 1 3
// split
// merge

// Follow up: Can you sort the linked list in O(n logn) time 
// and O(1) memory (i.e. constant space)?

// top down, O(logn) space time O(logn)
class Solution {
public:

    // divide into two part and return the start of the second part
    // the first part should also not connect to the second part anymore 
    ListNode* split(ListNode* head) {

        // fast slow pointer to find the mid
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // break the connection
        prev->next = nullptr;
        // return the second part
        return slow;
    }


    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1)
            ptr->next = list1;
        else
            ptr->next = list2;

        return dummyHead.next;
    }

    // merge two sorted list
    // [2, 4] [1, 3]
    // a 2
    // b 1
    // head = b
    // ListNode* merge(ListNode* a, ListNode* b) {

    //     ListNode* head;
    //     ListNode* prev;
    //     while (a && b) {

    //         ListNode* aNext = a->next;
    //         ListNode* bNext = b->next;

    //         if (a->val > b->val) {
    //             b->next = a;
    //             if (head == nullptr)
    //                 head = b;
    //             prev = b;
    //             b = bNext;
    //         } else {
    //             a->next = b;
    //             if (head == nullptr)
    //                 head = a;
    //             prev = a;
    //             a = aNext;
    //         }
    //     }
    //     if (b)
    //         prev->next = b;
    //     if (a)
    //         prev->next = a;
    //     return head;
    // }

    // 4] [2] [1 3
    // [2, 4] [1, 3]

    ListNode* sortList(ListNode* head) {

        // base case: if none or size 1
        if (!head || !head->next)
            return head;

        ListNode* secondPart = split(head);
        ListNode* firstPartSorted = sortList(head);
        ListNode* secondPartSorted = sortList(secondPart);
        ListNode* newHead = merge(firstPartSorted, secondPartSorted);
        return newHead;
    }
};

// top-down
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next) return head;
//         ListNode* mid = divide(head);
//         ListNode* left = sortList(head);
//         ListNode* right = sortList(mid);
//         return merge(left, right);
//     }

//     ListNode* merge(ListNode* list1, ListNode* list2) {
//         ListNode dummyHead(0);
//         ListNode* ptr = &dummyHead;
//         while (list1 && list2) {
//             if (list1->val < list2->val) {
//                 ptr->next = list1;
//                 list1 = list1->next;
//             } else {
//                 ptr->next = list2;
//                 list2 = list2->next;
//             }
//             ptr = ptr->next;
//         }
//         if (list1)
//             ptr->next = list1;
//         else
//             ptr->next = list2;

//         return dummyHead.next;
//     }

//     // finding the center and divide
//     ListNode* divide(ListNode* head) {
//         ListNode* prev = nullptr;
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // slow 現在在 mid（偶數長度時是右邊那個 mid）
//         if (prev)
//             prev->next = nullptr;  // cut 左半段
//         return slow;
//     }
// };



// bottom-up
// 先iterate全部切成size step, step = 1
// 分別兩兩merge
// 直到step >= n
// class Solution {
// public:
//     ListNode* tail = new ListNode();
//     ListNode* nextSubList = new ListNode();

//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next) return head;
//         int n = getCount(head);
//         ListNode* start = head;
//         ListNode dummyHead(0);
//         for (int size = 1; size < n; size = size * 2) {
//             tail = &dummyHead;
//             while (start) {
//                 if (!start->next) {
//                     tail->next = start;
//                     break;
//                 }
//                 ListNode* mid = split(start, size);
//                 merge(start, mid);
//                 start = nextSubList;
//             }
//             start = dummyHead.next;
//         }
//         return dummyHead.next;
//     }

//     ListNode* split(ListNode* start, int size) {
//         ListNode* midPrev = start;
//         ListNode* end = start->next;
//         // use fast and slow approach to find middle and end of second linked list
//         for (int index = 1; index < size && (midPrev->next || end->next);
//              index++) {
//             if (end->next) {
//                 end = (end->next->next) ? end->next->next : end->next;
//             }
//             if (midPrev->next) {
//                 midPrev = midPrev->next;
//             }
//         }
//         ListNode* mid = midPrev->next;
//         nextSubList = end->next;
//         midPrev->next = nullptr;
//         end->next = nullptr;
//         // return the start of second linked list
//         return mid;
//     }

//     void merge(ListNode* list1, ListNode* list2) {
//         ListNode dummyHead(0);
//         ListNode* newTail = &dummyHead;
//         while (list1 && list2) {
//             if (list1->val < list2->val) {
//                 newTail->next = list1;
//                 list1 = list1->next;
//                 newTail = newTail->next;
//             } else {
//                 newTail->next = list2;
//                 list2 = list2->next;
//                 newTail = newTail->next;
//             }
//         }
//         newTail->next = (list1) ? list1 : list2;
//         // traverse till the end of merged list to get the newTail
//         while (newTail->next) {
//             newTail = newTail->next;
//         }
//         // link the old tail with the head of merged list
//         tail->next = dummyHead.next;
//         // update the old tail with the new tail of merged list
//         tail = newTail;
//     }

//     int getCount(ListNode* head) {
//         int cnt = 0;
//         ListNode* ptr = head;
//         while (ptr) {
//             ptr = ptr->next;
//             cnt++;
//         }
//         return cnt;
//     }
// };