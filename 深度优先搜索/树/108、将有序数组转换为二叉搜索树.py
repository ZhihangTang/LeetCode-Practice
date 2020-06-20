'''
方法一：中序遍历：始终选择中间位置左边元素作为根节点
方法：helper（left，right)使用数组nums中索引从left到right
的元素创建BST
如果left>right,字树种不存在元素，返回空。
找出中间元素：p=(left+right)//2
创建根节点：root = TreeNode(nums[p])。
递归创建左子树 root.left = helper(left, p - 1) 和右子树 root.right = helper(p + 1, right)。
返回 helper(0, len(nums) - 1)。


'''

from typing import List
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def treeNodeToString(root):
    if not root:
        return "[]"
    output = ""
    queue = [root]
    current = 0
    while current != len(queue):
        node = queue[current]
        current = current + 1

        if not node:
            output += "null, "
            continue

        output += str(node.val) + ", "
        queue.append(node.left)
        queue.append(node.right)
    return "[" + output[:-2] + "]"


class Solution:
    def sortArrayToBST(self, nums: List[int]) -> TreeNode:
        def helper(left, right):
            if left > right:
                return None
            p = (left + right)
            root = TreeNode(nums[p])
            root.left = helper(left, p - 1)
            root.right = helper(p + 1, right)
            return root

        return helper(0, len(nums) - 1)

if __name__=='__main__':
    nums=[1,3,4,5,7,2]
    solution=Solution()
    tree=solution.sortArrayToBST(nums)
    ans=treeNodeToString(tree)
    print(ans)