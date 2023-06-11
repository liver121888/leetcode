# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        hare = tortoise = head

        while hare != None and hare.next != None:
            hare = hare.next.next
            tortoise = tortoise.next
            
            if hare is tortoise:
                return True
            
        return False
            
            
        
        