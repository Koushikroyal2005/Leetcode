from typing import List
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        n=len(s)
        ans,i=[],0
        while i<n:
            ans.append(s[i:i+k])
            i+=k
        ans[-1]+=fill*(k-len(ans[-1]))
        return ans