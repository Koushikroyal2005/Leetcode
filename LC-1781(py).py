class Solution:
    def beautySum(self, s: str) -> int:
        n,ans=len(s),0
        for i in range(n):
            hashmap={}
            for j in range(i,n):
                hashmap[s[j]]=hashmap.get(s[j],0)+1
                mini=min(hashmap.values())
                maxi=max(hashmap.values())
                ans+= maxi-mini
        return ans