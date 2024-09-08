# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: List[ListNode]
        """

        ans = [None] * k
    
        cur = head
        l = 0
        while cur is not None:
            cur = cur.next
            l+=1
        
        split_size = l // k
        num_remaining_parts = l % k
        
        cur = head
        for i in range(k):
            new_part = ListNode(0)
            tail = new_part

            current_size = split_size
            if num_remaining_parts > 0:
                num_remaining_parts -= 1
                current_size += 1
            for j in range(current_size):
                tail.next = ListNode(cur.val)
                tail = tail.next
                cur = cur.next
            ans[i] = new_part.next
                
        return ans