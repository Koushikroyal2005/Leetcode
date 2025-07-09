from typing import *
from collections import deque
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        vis=[[False]*m for _ in range(n)]
        def bfs(i,j):
            dq=deque()
            dq.append([i,j])
            dx,dy=[-1,1,0,0],[0,0,1,-1]
            while dq:
                r,c=dq.popleft()
                vis[r][c]=True
                for idx in range(4):
                    nr,nc=r+dx[idx],c+dy[idx]
                    if 0<=nr<n and 0<=nc<m and not vis[nr][nc] and grid[nr][nc]==1:
                        vis[nr][nc]=True
                        dq.append([nr,nc])
        for i in range(n):
            if not vis[i][0] and grid[i][0]==1: bfs(i,0)
            if not vis[i][m-1] and grid[i][m-1]==1: bfs(i,m-1)
        for j in range(m):
            if not vis[0][j] and grid[0][j]==1: bfs(0,j)
            if not vis[n-1][j] and grid[n-1][j]==1: bfs(n-1,j)
        cnt=0
        for i in range(n):
            for j in range(m):
                if not vis[i][j] and grid[i][j]==1: cnt+=1
        return cnt