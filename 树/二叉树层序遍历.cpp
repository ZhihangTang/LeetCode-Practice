#include<vector>
#include<iostram>


using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> LevelOrder(TreeNode* root){
    vector<TreeNode*> layer={root};
    vector<vector<int>> res;
    if(root==NULL) return res;
    while(layer){
        vector<int> this_res;
        vector<TreeNode*> next_layer;
        for(int i=0;i<layer.size();++i){
            this_res.push_back(layer[i]->val);
            if(layer[i]->left){
                next_layer.push_back(layer[i]->left);
            }
            if(layer[i]->right){
                next_layer.push_back(layer[i]->right);
            }
        }
        res.push_back(this_res);
        layer=next_layer;
    }
}
	