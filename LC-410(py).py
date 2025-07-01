from typing import *
class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        n=len(nums)
        s,e=max(nums),sum(nums)
        def check(mid):
            ans,cnt=0,1
            for i in nums:
                ans+=i
                if ans>mid:
                    ans=i
                    cnt+=1
                if cnt>k: return False
            return True
        while s<=e:
            mid=(s+e)//2
            if check(mid):
                e=mid-1
            else: s=mid+1
        return s