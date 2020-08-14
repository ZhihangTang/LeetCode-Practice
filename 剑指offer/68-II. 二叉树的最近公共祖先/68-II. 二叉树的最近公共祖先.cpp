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
    // print list for debug
    // void Print(list<TreeNode*>path){
    //     list<TreeNode*>::iterator iter=path.begin();
    //     TreeNode* p=nullptr;
    //     while(iter!=path.end()){
    //         p=*iter;
    //         cout<<p->val<<"->";
    //         iter++;
    //     }
    //     cout<<endl;
    // }
    bool GetNodePath(TreeNode* root,TreeNode* p,list<TreeNode*>& path){
        if(root==p){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        bool found=false;
        if(!found&&root->left){
            found=GetNodePath(root->left,p,path);
        }
        if(!found&&root->right){
            found=GetNodePath(root->right,p,path);
        }
        if(!found)
            path.pop_back();
        return found;
    }

    TreeNode* GetLastCommonNode(
        const list<TreeNode*>& path1,
        const list<TreeNode*>& path2){
        list<TreeNode*>::const_iterator iterator1=path1.begin();
        list<TreeNode*>::const_iterator iterator2=path2.begin();
        TreeNode* pLast=nullptr;

        while(iterator1!=path1.end()&&iterator2!=path2.end()){
            if(*iterator1==*iterator2)
                pLast=*iterator1;
            iterator1++;
            iterator2++;
        }
        return pLast;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(p==nullptr||p==nullptr||q==nullptr){
            return nullptr;
        }
        list<TreeNode*> path1;

        list<TreeNode*> path2;

        GetNodePath(root,p,path1);
        GetNodePath(root,q,path2);
        
        // cout<<path1.size()<<endl;
        // cout<<path2.size()<<endl;
        // Print(path1);
        // Print(path2);
        return GetLastCommonNode(path1,path2);
    }

};