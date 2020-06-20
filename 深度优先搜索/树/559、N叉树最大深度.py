# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        cur = 0
        for i in range(len(root.children)):
            cur = max(cur, self.maxDepth(root.children[i]))
        cur += 1
        return cur
