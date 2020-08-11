解题思路：
二叉搜索树的中序遍历是按从小到大的顺序排列的。
通过一个全局变量count和全部变量node
中序遍历，通过count计数，当count==k时返回n当前节点。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<int> res;
    int count=0;
    TreeNode* node=nullptr;
    TreeNode* KthNode(TreeNode* pRoot, int k){
        Inorder(pRoot,k);
        return node;
    }
    void Inorder(TreeNode* root,int k){
        if(root!=nullptr){
                Inorder(root->left,k);
                count++;
                if(count==k){
                    node=root;
                }
              Inorder(root->right, k);
        }
    }
};