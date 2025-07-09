from typing import *
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n,m=len(board),len(board[0])
        vis=[[False]*m for _ in range(n)]
        dx,dy=[-1,1,0,0],[0,0,1,-1]
        def dfs(i,j):
            if vis[i][j]: return
            vis[i][j]=True
            for idx in range(4):
                r,c=i+dx[idx],j+dy[idx]
                if 0<=r<n and 0<=c<m and not vis[r][c] and board[r][c]=='O':
                    dfs(r,c)

        for i in range(n):
            for j in range(m):
                if not vis[i][j] and (i==0 or i==n-1 or j==0 or j==m-1) and board[i][j]=='O':
                    dfs(i,j)
        for i in range(n):
            for j in range(m):
                if not vis[i][j]: board[i][j]='X'