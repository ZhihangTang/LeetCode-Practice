# 递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left=0,right=0;
        if(root->left){
            left=maxDepth(root->left);
        }
        if(root->right){
            right=maxDepth(root->right);
        }
        return max(left,right)+1;
    }
};