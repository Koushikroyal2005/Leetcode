from typing import *
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n=len(nums)
        s,e,mini=0,n-1,nums[0]
        while s<=e:
            mid=(s+e)//2
            if nums[s]<=nums[mid]:
                mini=min(mini,nums[s])
                s=mid+1
            else:
                mini=min(mini,nums[mid])
                e=mid-1
        return mini