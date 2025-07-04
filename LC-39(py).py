from typing import *
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n=len(candidates)
        ans=[]
        def func(ind,ans1,tot):
            if tot>target:
                return
            if tot==target:
                ans.append(ans1[:])
                return
            for i in range(ind,n):
                ans1.append(candidates[i])
                func(i,ans1,tot+candidates[i])
                ans1.pop()
        func(0,[],0)
        return ans