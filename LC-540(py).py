from typing import *
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1: return nums[0]
        if nums[0]!=nums[1]: return nums[0]
        if nums[n-1]!=nums[n-2]: return nums[n-1]
        s,e=0,n-1
        while s<=e:
            mid=(s+e)//2
            if nums[mid-1]!=nums[mid]!=nums[mid+1]: return nums[mid]
            if (mid%2==1 and nums[mid]==nums[mid-1]) or (mid%2==0 and nums[mid]==nums[mid+1]):
                s=mid+1
            else: e=mid-1
        return -1