class Solution:    
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
                
        safe_nodes = set()
        # from observation, we could see with cycle, then not safe node
        n = len(graph)     
        node_stack = []
        visited = [False] * n
             
        def dfs(start):
            if visited[start]:
                return
            # print(start)
            # print(node_stack)
            visited[start] = True
            node_stack.append(start)
            
            if not graph[start]:
                # terminal node also safe node
                safe_nodes.add(start)
                # print(safe_nodes)
                node_stack.pop()
                return

            for vertex in graph[start]:
                dfs(vertex)
            for vertex in graph[start]:
                if vertex not in safe_nodes:   
                    return
            safe_nodes.add(start)
            node_stack.pop()
        
        
        for i in range(n):
            dfs(i)
        ans = list(safe_nodes)
        ans.sort()
        return ans

            

            
            
        