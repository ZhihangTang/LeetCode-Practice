

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL &&root->right!=NULL){
            return 1+minDepth(root->right);
        }
        if(root->left!=NULL &&root->right==NULL){
            return 1+minDepth(root->left);
        }
        int left_depth=minDepth(root->left);
        int right_depth=minDepth(root->right);
        return min(left_depth,right_depth)+1;
    }
};