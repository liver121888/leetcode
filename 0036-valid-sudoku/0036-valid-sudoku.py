class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        m = len(board)
        n = len(board[0])   
        checkcols = [set() for i in range(n)]
        checkrows = [set() for i in range(m)]
        checksquares = collections.defaultdict(set)

        for i in range(m):
            for j in range(n):
                cur = board[i][j]
                if cur == '.':
                    continue
                
                if cur in checkrows[i] or cur in checkcols[j] or cur in checksquares[(i//3, j//3)]:
                    return False
                
                checkrows[i].add(cur)
                checkcols[j].add(cur)
                checksquares[(i//3, j//3)].add(cur)
        return True
        