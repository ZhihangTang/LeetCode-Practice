'''
C++ BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        return max(leftdepth,rightdepth)+1;
    }
};
'''


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # dfs
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    def maxDepth2(self, root: TreeNode) -> int:
        # bfs
        level = 0
        if root == None:
            return level
        quece = [root]
        while len(quece):
            len = len(quece)
            while len:
                len -= 1
                curNode = quece.pop(0)


