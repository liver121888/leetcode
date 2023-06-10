# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        greater = p.val if p.val > q.val else q.val
        smaller = q.val if greater == p.val else p.val

        if root.val > greater:
            ans = self.lowestCommonAncestor(root.left, p, q)
        elif root.val < smaller:
            ans = self.lowestCommonAncestor(root.right, p, q)
        else:
            return root
        
        return ans