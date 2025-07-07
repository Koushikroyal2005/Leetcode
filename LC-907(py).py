from typing import *
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n=len(arr)
        st=[]
        left,right=[-1]*n,[n]*n
        for i in range(n):
            if not st:
                st.append(i)
            else:
                while st and arr[i]<arr[st[-1]]:
                    st.pop()
                left[i]= st[-1] if st else -1
                st.append(i)
        st=[]
        for i in range(n-1,-1,-1):
            if not st:
                st.append(i)
            else:
                while st and arr[i]<=arr[st[-1]]:
                    st.pop()
                right[i]=st[-1] if st else n
                st.append(i)
        ans=0
        mod=10**9+7
        for i in range(n):
            ans = (ans + arr[i]*((i-left[i])*(right[i]-i))%mod)%mod
        return ans