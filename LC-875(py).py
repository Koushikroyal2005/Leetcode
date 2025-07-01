from typing import *
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        s,e=1,0
        for i in piles:
            e=max(e,i)
        def check(num):
            ans=0
            for i in piles:
                ans+=(i//num)
                if i%num!=0: ans+=1
                if ans>h: return False
            return True
        tot=e
        while s<=e:
            mid=(s+e)//2
            if check(mid):
                tot=mid
                e=mid-1
            else: s=mid+1
        return tot