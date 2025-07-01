from typing import *
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        n=len(nums)
        s,e=1,0
        for i in nums:
            e=max(e,i)
        def check(mid):
            ans=0
            for i in nums:
                ans+=(i//mid)
                if i%mid!=0: ans+=1
                if ans>threshold: return False
            return True
        while s<=e:
            mid=(s+e)//2
            if check(mid):
                e=mid-1
            else:
                s=mid+1
        return s