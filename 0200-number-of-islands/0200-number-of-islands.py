class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        
        visited = set()
        ans = 0
        
        def bfs(r, c):
            q = []
            visited.add((r, c))
            q.append((r, c))
            
            while q:
                row, col = q.pop(0)
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
                
                for dr, dc in directions:
                    r = row + dr
                    c = col + dc
                    if (r in range(rows) and 
                        c in range(cols) and
                        grid[r][c] == "1" and 
                        (r, c) not in visited):
                            
                        visited.add((r, c))
                        bfs(r, c)       
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    ans += 1
                    
        return ans