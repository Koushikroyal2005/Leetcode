"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
from typing import *
from xml.dom import Node

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        temp=head
        hashmap={}
        while temp:
            hashmap[temp]=Node(temp.val)
            temp=temp.next
        temp=head
        while temp:
            hashmap[temp].next=hashmap.get(temp.next)
            hashmap[temp].random=hashmap.get(temp.random)
            temp=temp.next
        return hashmap[head]