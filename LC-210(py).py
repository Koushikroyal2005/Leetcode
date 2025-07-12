from typing import *
from collections import deque
# dfs 
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for u, v in prerequisites:
            adj[v].append(u)
        vis = [0] * numCourses
        ans = []
        def dfs(node: int) -> bool:
            if vis[node] == 1:
                return False
            if vis[node] == 2:
                return True
            vis[node] = 1
            for neighbor in adj[node]:
                if not dfs(neighbor):
                    return False
            vis[node] = 2
            ans.append(node)
            return True
        for i in range(numCourses):
            if vis[i] == 0:
                if not dfs(i):
                    return []
        return ans[::-1]
    
# topo
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        n=len(prerequisites)
        adj=[[] for _ in range(numCourses)]
        indegree=[0]*numCourses
        for u,v in prerequisites:
            adj[v].append(u)
            indegree[u]+=1
        nodes=deque()
        for i in range(numCourses):
            if indegree[i]==0:
                nodes.append(i)
        ans=[]
        while nodes:
            node=nodes.popleft()
            ans.append(node)
            for i in adj[node]:
                indegree[i]-=1
                if indegree[i]==0: nodes.append(i)
        return ans if len(ans)==numCourses else []