from typing import *
class Solution:
    def trap(self, height: List[int]) -> int:
        n=len(height)
        ans=0
        i,j=0,n-1
        left,right=0,0
        while i<=j:
            if height[i]<=height[j]:
                if height[i]>=left: left=height[i]
                else: ans+= left-height[i]
                i+=1
            else:
                if height[j]>=right: right=height[j]
                else: ans+= right-height[j]
                j-=1
        return ans