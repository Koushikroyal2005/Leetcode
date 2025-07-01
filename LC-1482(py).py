from typing import *
class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n=len(bloomDay)
        if m*k>n: return -1
        s,e=1,0
        for i in bloomDay:
            e=max(e,i)
        def check(mid):
            ans,cnt=0,0
            for i in bloomDay:
                if i>mid:
                    ans+=(cnt//k)
                    cnt=0
                else: cnt+=1
            ans+=(cnt//k)
            return ans>=m
        while s<=e:
            mid=(s+e)//2
            if check(mid):
                e=mid-1
            else: s=mid+1
        return s