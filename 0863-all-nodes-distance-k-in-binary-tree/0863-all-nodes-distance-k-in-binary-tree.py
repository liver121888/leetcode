# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.graph = {}
        self.visited = set()
        self.ans = []

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        # because tree cannot find parent, we need to build graph
        self.buildGraph(root, None)
        print(self.graph)
        self.visited = set()
        self.dfs(target.val, k)
        # if target.val in self.ans and k != 0:
        #     self.ans.remove(target.val)
        return self.ans
        
    def buildGraph(self, root: TreeNode, parent: TreeNode):
        if root is None:
            return
        if root.val not in self.visited:
            self.graph[root.val] = []
            self.visited.add(root.val)
        
            if root.left is not None:
                self.graph[root.val].append(root.left.val)
            if root.right is not None:
                self.graph[root.val].append(root.right.val)
            if parent is not None:
                self.graph[root.val].append(parent.val)

            self.buildGraph(root.left, root)
            self.buildGraph(root.right, root)
        
    
        
    def dfs(self, target: int, k: int):
        if k == 0:
            self.ans.append(target)
            return
        self.visited.add(target)
        for neighbor in self.graph[target]:
            if neighbor not in self.visited:
                self.visited.add(neighbor)
                self.dfs(neighbor, k - 1)
                    
        