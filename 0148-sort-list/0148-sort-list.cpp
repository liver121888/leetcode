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
class Solution {
public:
    ListNode* tail = new ListNode();
    ListNode* nextSubList = new ListNode();

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int n = getCount(head);
        ListNode* start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next) {
                    tail->next = start;
                    break;
                }
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode* split(ListNode* start, int size) {
        ListNode* midPrev = start;
        ListNode* end = start->next;
        // use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next || end->next);
             index++) {
            if (end->next) {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next) {
                midPrev = midPrev->next;
            }
        }
        ListNode* mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode dummyHead(0);
        ListNode* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};