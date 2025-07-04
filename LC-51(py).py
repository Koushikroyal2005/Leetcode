from typing import *
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        if n==1: return [["Q"]]
        if n<4: return []
        board=[['.']*n for _ in range(n)]
        ans=[]
        def issafe(board,i,j):
            for c in range(i-1,-1,-1):
                if board[c][j]=='Q': return False
            r,c=i,j
            while r>=0 and c>=0:
                if board[r][c]=='Q': return False
                r-=1
                c-=1
            r,c=i,j
            while r>=0 and c<n:
                if board[r][c]=='Q': return False
                r-=1
                c+=1
            return True
        def func(i):
            if i==n:
                ans.append([''.join(row) for row in board])
                return
            for j in range(n):
                if issafe(board,i,j):
                    board[i][j]='Q'
                    func(i+1)
                    board[i][j]='.'
        func(0)
        return ans