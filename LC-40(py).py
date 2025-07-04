from typing import *
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n=len(candidates)
        candidates.sort()
        ans=[]
        def func(ind,tot,ans1):
            if tot>target: return
            if tot==target:
                ans.append(ans1[:])
                return
            for i in range(ind,n):
                if i>ind and candidates[i]==candidates[i-1]: continue
                ans1.append(candidates[i])
                func(i+1,tot+candidates[i],ans1)
                ans1.pop()
        func(0,0,[])
        return ans
