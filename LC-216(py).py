from typing import *
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans=[]
        def func(ind,tot,cnt,ans1):
            if tot>n or cnt>k: return
            if tot==n and cnt==k:
                ans.append(ans1[:])
                return
            for i in range(ind,10):
                ans1.append(i)
                func(i+1,tot+i,cnt+1,ans1)
                ans1.pop()
        func(1,0,0,[])
        return ans
            