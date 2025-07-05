from typing import *
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        num=0
        for i in nums:
            num=num^i
        bit=1
        while num&(bit)==0:
            bit=bit<<1
        a,b=0,0
        for i in nums:
            if i&bit: a=a^i
            else: b=b^i
        return [a,b]