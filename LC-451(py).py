class Solution:
    def frequencySort(self, s: str) -> str:
        n=len(s)
        hash1,arr={},[]
        for i in s:
            if i not in hash1:
                hash1[i]=1
            else: hash1[i]+=1
        for i in hash1:
            arr.append([hash1[i],i])
        arr.sort(key=lambda x:-x[0])
        ans=""
        for i,j in arr:
            ans+=(j*i)
        return ans
        