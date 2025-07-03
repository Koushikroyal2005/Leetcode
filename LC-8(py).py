class Solution:
    def myAtoi(self, s: str) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        i,n,ans,neg=0,len(s),0,1
        while i<n and s[i]==' ':
            i+=1
        if i<n and (s[i]=='+' or s[i]=='-'):
            if s[i]=='-':
                neg=-1
            i+=1
        while i<n and s[i].isdigit():
            ans=ans*10+int(s[i])
            i+=1
            if neg*ans<INT_MIN:
                return INT_MIN
            if neg*ans>INT_MAX:
                return INT_MAX
        return neg*ans
