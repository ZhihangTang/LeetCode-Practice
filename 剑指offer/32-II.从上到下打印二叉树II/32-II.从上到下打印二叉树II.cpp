/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
        if(root==NULL) return {};
		vector<TreeNode*> layer={root};
		vector<vector<int>> res;
		while(layer.size()>0){
			vector<TreeNode*> next_layer;
			vector<int> this_res;
			for(int i=0;i<layer.size();++i){
				this_res.push_back(layer[i]->val);
				if(layer[i]->left){
					next_layer.push_back(layer[i]->left);
				}
				if(layer[i]->right){
					next_layer.push_back(layer[i]->right);
				}
			}
			layer=next_layer;
			res.push_back(this_res);
		}
		return res;
	}
};