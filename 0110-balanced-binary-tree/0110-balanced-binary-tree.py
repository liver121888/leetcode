# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True
        
        leftHeight = self.checkHeight(root.left, 0)
        rightHeight = self.checkHeight(root.right, 0)
        
        
        if abs(leftHeight - rightHeight) > 1 or not self.isBalanced(root.left) or not self.isBalanced(root.right):
            return False
        else:
            return True
        
    def checkHeight(self, root: TreeNode, prevDepth) -> int:
        
        if root is None:
            return prevDepth
        
        depth = prevDepth + 1
                
        leftHeight = self.checkHeight(root.left, depth)
        rightHeight = self.checkHeight(root.right, depth)
        
        return leftHeight if leftHeight > rightHeight else rightHeight
        
        