# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0 
        
        lDepth = self.calDepth(root.left)
        rDepth = self.calDepth(root.right)
        
        # maxDepth must occur at root, so we don't need to traverse check like the 543 feDiameter of Binary Tree
        return 1 + max(lDepth, rDepth)
        
        
        
    def calDepth(self, root):
        if root is None:
            return 0
        
        return 1 + max(self.calDepth(root.left), self.calDepth(root.right))
        
        
        
        