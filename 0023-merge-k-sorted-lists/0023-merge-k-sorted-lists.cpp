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


// I can compare each of the head of the lists
// find the samllest, find the next, and connect the smallest
// move the smallest to the next
// this can be done in logn
// each linked list can have different length
// we will do this in time n*logk
// in which n is the longest length in the lists


// lists[i] is sorted in ascending order
// if lists[i][0] lists[j][0] is equal, we can take any of them


// Input: lists = []
// Output: []

// Input: lists = [[]]
// Output: []

// lists = [[1,4,5],[1,3,4],[2,6]]
// [1,1,2,3,4,4,5,6]

// dummy -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

class Solution {
public:

    // we create a compare struct with () oeprator
    // so that it's a custom compare
    struct compare {
        // add const key word to make sure we are not modifying
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode dummy = ListNode();
        ListNode* dummyHead = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // skip empty list
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }

        ListNode* curr = dummyHead;
        while (!pq.empty()) {
            ListNode* currSmallest = pq.top();
            pq.pop();

            if (currSmallest->next)
                pq.push(currSmallest->next);

            // break the connection 
            currSmallest->next = nullptr;
            curr->next = currSmallest;
            curr = curr->next;
        }
        return dummyHead->next;
    }
};