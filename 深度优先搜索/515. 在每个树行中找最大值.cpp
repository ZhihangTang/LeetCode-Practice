515. 在每个树行中找最大值
您需要在二叉树的每一行中找到最大的值。

示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]


思路，二叉树的层序遍历，每次更新当前层数最大值，每层遍历完成后保存最大值。



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
    vector<int> largestValues(TreeNode* root) {
    	vector<int> res;
    	if(root==NULL) return res;
    	vector<TreeNode*> layer={root};
    	int cur_max=INT_MIN;
    	while(layer.size()>0){
    		vector<TreeNode*> next_layer;
    		for(int i=0;i<layer.size();++i){
    			cur_max=max(cur_max,layer[i]->val);
    			if(layer[i]->left){
    				next_layer.push_back(layer[i]->left);
    			}
    			if(layer[i]->right){
    				next_layer.push_back(layer[i]->right);
    			}
    		}
    		layer=next_layer;
    		res.push_back(cur_max);
    		cur_max=INT_MIN;
    	}
    	return res;

    }
};