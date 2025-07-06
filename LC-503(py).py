from typing import *
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n=len(nums)
        ans,st=[-1]*len(nums),[]
        for i in range(2*n-1,-1,-1):
            while st and st[-1]<=nums[i%n]:
                st.pop()
            if i<n and st: ans[i]=st[-1]
            st.append(nums[i%n])
        return ans