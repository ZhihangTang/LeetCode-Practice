# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        layer=[root]
        res=[]
        if(root==None):
            return res
        while len(layer):

            this_res=[]
            next_layer=[]
            for i in range(len(layer)):
                this_res.append(layer[i].val)
                if layer[i].left:
                    next_layer.append(layer[i].left)
                if layer[i].right:
                    next_layer.append(layer[i].right)
            res.append(this_res)
            layer=next_layer
        
        return res