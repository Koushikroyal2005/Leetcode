from typing import *
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        n=len(weights)
        s,e=max(weights),sum(weights)
        def check(mid):
            ans,cnt,=0,1
            for i in weights:
                if ans+i>mid:
                    ans=0
                    cnt+=1
                ans+=i
            return cnt<=days
        while s<=e:
            mid=(s+e)//2
            if check(mid):
                e=mid-1
            else: s=mid+1
        return s