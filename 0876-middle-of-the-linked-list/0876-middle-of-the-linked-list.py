# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # The problem constraints guarantee to have a head
        if head.next is None:
            return head
        
        tortoise = hare = head
        
        while hare and hare.next:
            hare = hare.next.next
            tortoise = tortoise.next
        
        return tortoise