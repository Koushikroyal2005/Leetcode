from typing import *
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
            # memiozation
        dp=[-1]*n
        def func(i):
            if i==0: return nums[i]
            if i<0: return 0
            if dp[i]!=-1: return dp[i]
            take=nums[i]+func(i-2)
            nottake=func(i-1)
            dp[i]= max(take,nottake)
            return dp[i]
        #return func(n-1)
            # tabulation
        if n==1: return nums[0]
        dp=[0]*n
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])
        for i in range(2,n):
            dp[i]=max(dp[i-1],nums[i]+dp[i-2])
        #return dp[n-1]
            # space optimization
        if n==1: return nums[0]
        a,b,c=nums[0],max(nums[0],nums[1]),0
        for i in range(2,n):
            c=max(b,a+nums[i])
            a,b=b,c
        return b