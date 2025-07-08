from typing import *
from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])
        vis=[[False]*m for _ in range(n)]
        dq=deque()
        rot,org=0,0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==2: 
                    dq.append([i,j,0])
                    vis[i][j]=True
                    rot+=1
                    org+=1
                elif grid[i][j]==0: vis[i][j]=True
                else: org+=1
        tot=0
        dx,dy=[1,-1,0,0],[0,0,1,-1]
        while dq:
            i,j,cnt=dq.popleft()
            tot=max(tot,cnt)
            for idx in range(4):
                r,c=i+dx[idx],j+dy[idx]
                if 0<=r<n and 0<=c<m and not vis[r][c] and grid[r][c]==1:
                    rot+=1
                    vis[r][c]=True
                    dq.append([r,c,cnt+1])
        return tot if rot==org else -1