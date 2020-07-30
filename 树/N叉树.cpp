//后序
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(root){
            for(int i=0;i<root->children.size();++i){
                postorder(root->children[i]);
            }
            res.push_back(root->val);
        }
        return res;
    }

};

//前序
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {

        if(root){
            res.push_back(root->val);
            for(int i=0;i<root->children.size();++i){
                preorder(root->children[i]);
            }
        }
        return res;
    }
};


//层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<Node*> layer={root};
        vector<vector<int>> res;
        while(!layer.empty()){
            vector<Node*> next_layer={};
            vector<int> this_res;
            for(int i=0;i<layer.size();++i){
                this_res.push_back(layer[i]->val);
                for(int j=0;j<layer[i]->children.size();++j){
                    next_layer.push_back(layer[i]->children[j]);
                }

            }
            res.push_back(this_res);
            layer=next_layer;
        }
        return res;
    }
};