
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution{
public:
    ListNode* getMid(ListNode* left,ListNode* right){
        ListNode* fast=left;
        ListNode* slow=left;
        while(fast!=right&&fast->next!=right){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    TreeNode* buildTree(ListNode* left,ListNode* right){
        if(left==right){
            return nullptr;
        }
        ListNode* mid=getMid(left,right);
        TreeNode* root=new TreeNode(mid->val);
        root->left=buildTree(left,mid);
        root->right=buildTree(mid->next,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head){
        return buildTree(head,nullptr);
    }
}
;