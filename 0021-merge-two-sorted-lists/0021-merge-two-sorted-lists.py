# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:        
        
        if not list1 and not list2:
            return None
        elif list1 and not list2:
            return list1
        elif not list1 and list2:
            return list2
                    
        ans = ListNode()
        cur = ans
        while list1 and list2:
            tmp = ListNode()
            if list1.val < list2.val:
                tmp.val = list1.val
                cur.next = tmp
                list1 = list1.next
            else:
                tmp.val = list2.val
                cur.next = tmp
                list2 = list2.next
            cur = cur.next
        if not list1:
            cur.next = list2
        if not list2:
            cur.next = list1  
            
        return ans.next

            
        