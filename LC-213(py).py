from typing import *
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
            # memoization
        dp1=[-1]*n
        dp2=[-1]*n
        def func1(i):
            if i==1: return nums[i]
            if i<1: return 0
            if dp1[i]!=-1: return dp1[i]
            take=nums[i]+func1(i-2)
            nottake=func1(i-1)
            dp1[i]= max(take,nottake)
            return dp1[i]
        def func2(i):
            if i==0: return nums[0]
            if i<0: return 0
            if dp2[i]!=-1: return dp2[i]
            take=nums[i]+func2(i-2)
            nottake=func2(i-1)
            dp2[i]= max(take,nottake)
            return dp2[i]
        #return max(func1(n-1),func2(n-2))
            # tabulation
        if n==1: return nums[0]
        dp1=[0]*n
        dp2=[0]*n
        for i in range(1,n):
            take=nums[i]
            if i>2: take+=dp1[i-2]
            nottake=dp1[i-1]
            dp1[i]=max(take,nottake)
        for i in range(0,n-1):
            take=nums[i]
            if i>1: take+=dp2[i-2]
            nottake=dp2[i-1]
            dp2[i]=max(take,nottake)
        return max(dp1[n-1],dp2[n-2])