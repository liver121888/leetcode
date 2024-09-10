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
    int gcd(int a, int b) {
        int smaller = min(a, b);
        while (smaller > 0) {
            if (a % smaller == 0 && b % smaller == 0)
                return smaller;
            smaller -= 1;
        }
        return 0; 
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* ans = new ListNode(0, head);
        ListNode* prev = ans;
        ListNode* cur = head;
        while (cur) {
            if (prev->val != 0) {
                // find gcd of prev and cur
                int divisor = gcd(prev->val, cur->val);
                ListNode* tmp = new ListNode(divisor, cur);
                prev->next = tmp;
            }          
            prev = cur;
            cur = cur->next;    
        }
        return ans->next;
    }
};