from typing import *
import heapq

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n,m=len(heights),len(heights[0])
        dist=[[1e9]*m for _ in range(n)]
        dist[0][0]=0
        dx,dy=[0,0,1,-1],[1,-1,0,0]
        pq=[]
        heapq.heappush(pq,[0,0,0])
        while pq:
            [dis,r,c]=heapq.heappop(pq)
            if r==n-1 and c==m-1: return dis
            for i in range(4):
                nr,nc=r+dx[i],c+dy[i]
                if 0<=nr<n and 0<=nc<m:
                    diff=max(abs(heights[r][c]-heights[nr][nc]),dis)
                    if diff<dist[nr][nc]:
                        dist[nr][nc]=diff
                        heapq.heappush(pq,[diff,nr,nc])
        return 0