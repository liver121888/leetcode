# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        lHeight = self.calHeight(root.left)       
        rHeight = self.calHeight(root.right)
        
        lDiameter = self.diameterOfBinaryTree(root.left)
        rDiameter = self.diameterOfBinaryTree(root.right)
        
        return max(lHeight + rHeight, max(lDiameter, rDiameter))
        

    def calHeight(self, root) -> int:
        if root is None:
            return 0
        
        return 1 + max(self.calHeight(root.left), self.calHeight(root.right))
        
        