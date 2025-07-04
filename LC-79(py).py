from typing import *
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n,m=len(board),len(board[0])
        dx,dy=[-1,1,0,0],[0,0,1,-1]
        def func(i,r,c):
            if i==len(word):
                return True
            for j in range(4):
                nr=r+dx[j]
                nc=c+dy[j]
                if 0<=nr<n and 0<=nc<m and board[nr][nc]!='#' and word[i]==board[nr][nc]:
                    temp=board[nr][nc]
                    board[nr][nc]='#'
                    if func(i+1,nr,nc): return True
                    board[nr][nc]=temp
            return False
        for i in range(n):
            for j in range(m):
                if board[i][j]==word[0]:
                    temp=board[i][j]
                    board[i][j]='#'
                    if func(1,i,j): return True
                    board[i][j]=temp
        return False