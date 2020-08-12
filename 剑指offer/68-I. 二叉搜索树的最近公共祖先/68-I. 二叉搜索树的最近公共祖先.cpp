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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p||root==q) return root;
        
        int pval=p->val;
        int qval=q->val;
        int mid=root->val;
        if(pval<mid&&qval<mid){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(pval>mid&&qval>mid){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
        
    }
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *left, *right;
		// 1、既可表示空、也可表示root为NUll
		if (!root) return NULL;
		// 1、若root等于p或q
		if (root == p || root == q) return root;

		left = lowestCommonAncestor(root->left, p, q);
		right = lowestCommonAncestor(root->right, p, q);
		// 2、若左右均有
		if (left && right) return root;
		// 2、若左有或右有
		if (left && !right) return left;
		if (!left && right) return right;
	    // 2、先假设左右均为NULL，则
		return NULL;
	}
};