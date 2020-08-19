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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int l=depth(root->left);
        int r=depth(root->right);
        if(abs(l-r)<=1){
            return isBalanced(root->left)&&isBalanced(root->right);
        } 
        else return false;
    }
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        return max(left,right)+1;
    }
};