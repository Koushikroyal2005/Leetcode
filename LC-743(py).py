from typing import *
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj=[[] for _ in range(n)]
        dist=[1e9]*n
        for u,v,w in times:
            adj[u-1].append([v-1,w])
        pq=[(0,k-1)]
        dist[k-1]=0
        while pq:
            cost,node=heapq.heappop(pq)
            for v,w in adj[node]:
                if cost+w<dist[v]:
                    dist[v]=cost+w
                    heapq.heappush(pq,(cost+w,v))
        mini=0
        for i in range(n):
            if dist[i]==1e9: return -1
            else:
                mini=max(mini,dist[i])
        return mini