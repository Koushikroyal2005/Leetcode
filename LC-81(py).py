from typing import *

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n=len(nums)
        s,e=0,n-1
        while s<=e:
            mid=(s+e)//2
            if nums[mid]==target: 
                return True
            if nums[s]==nums[mid] and nums[mid]==nums[e]:
                s=s+1
                e=e-1
                continue
            if nums[s]<=nums[mid]:
                if nums[s]<=target and target<=nums[mid]: e=mid-1
                else: s=mid+1
            else:
                if nums[mid]<=target and target<=nums[e]: s=mid+1
                else: e=mid-1
        return False