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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());
                    
        ListNode* prev = new ListNode();
        ListNode* ans;
        ans = prev;
        prev->next = head;
        while (head != nullptr) {
            if (toRemove.find(head->val) != toRemove.end()) {
               prev->next = head->next;     
            } else {
                prev = head;
            }
            head = head->next;
        }          
        
        return ans->next;
    }
};