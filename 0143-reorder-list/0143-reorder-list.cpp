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


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// tail
// progress back
// we connect head to tail and move to the next pairs
// vector<ListNode*>
// so that we can easily access the back and the front
// O(n) two pass
// O(n) space

// []
// [1]
// [1 2]

class Solution {
public:
    void reorderList(ListNode* head) {

        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int l = 0, r = nodes.size() - 1;
        ListNode* prevBackNode = nullptr;
        // [1 2 3 4 5]
        // 1 -> 5 -> 2 -> 4 -> 3

        while (l <= r) {
            // cout << l << " " << r << endl;
            ListNode* frontNode = nodes[l];
            ListNode* backNode = nodes[r];
            if (prevBackNode) {
                // cout << prevBackNode->val << endl;
                prevBackNode->next = frontNode;
            }
            frontNode->next = backNode;
            prevBackNode = backNode;
            l++;
            r--;
        }
        // cout << prevBackNode->val << endl;
        // break the loop
        prevBackNode->next = nullptr;
    
    }
};