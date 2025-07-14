from typing import *
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n=len(triangle)
        dp=[[-1]*n for _ in range(n)]
        def func(i,j):
            if j>i: return 1e9
            if i==n-1: return triangle[i][j]
            if dp[i][j]!=-1: return dp[i][j]
            down=triangle[i][j]+func(i+1,j)
            left=triangle[i][j]+func(i+1,j+1)
            dp[i][j]= min(down,left)
            return dp[i][j]
        # return func(0,0)
            # tabulation
        dp=[[0]*n for _ in range(n)]
        for i in range(n):
            dp[n-1][i]=triangle[n-1][i]
        for i in range(n-2,-1,-1):
            for j in range(i,-1,-1):
                down=triangle[i][j]+dp[i+1][j]
                left=triangle[i][j]+dp[i+1][j+1]
                dp[i][j]=min(down,left)
        return dp[0][0]