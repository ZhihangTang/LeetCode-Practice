''''
DFS解决的是连通性问题，即给定两个起始点，或某种起始状态和一个终点（或某种最终状态）
判断是否有一条路径能从起点连接到终点。
很多情况下，连通的路径有很多条，只需要找出一条即可，DFS只关心路径存在与否，不在乎其长短。

树的结构非常适合递归方法进行搜索
通常结构
dfs（TreeNode* root）{
    if root==NULL:
        return
    else:
        left =dfs(root->left)
        right=dfs(root->right)
    return
'''


