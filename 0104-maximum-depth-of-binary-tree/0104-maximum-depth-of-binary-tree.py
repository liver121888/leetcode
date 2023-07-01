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
        
        # maxDepth must occur at root, so we don't need to traverse check like 543 Diameter of Binary Tree
                
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right)) 
        
        
        
        