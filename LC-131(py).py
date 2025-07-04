from typing import *
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n=len(s)
        ans=[]
        def ispalindrome(str1):
            return str1==str1[::-1]
        def func(i,ans1):
            if i==n:
                ans.append(ans1[:])
                return
            for j in range(i,n):
                if ispalindrome(s[i:j+1]):
                    ans1.append(s[i:j+1])
                    func(j+1,ans1)
                    ans1.pop()
        func(0,[])
        return ans