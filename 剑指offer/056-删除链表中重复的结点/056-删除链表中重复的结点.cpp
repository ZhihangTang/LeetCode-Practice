

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
    	ListNode* head= new ListNode(0);
    	head->next=pHead;
    	ListNode* pre=head;//前一个节点
    	ListNode* p=head->next;//当前处理节点
    	while(p!=nullptr && p->next!=nullptr){
    		if(p->val==p->next->val){
    			while(p->next!=nullptr&&p->next->val==p->val){
    				p->next=p->next->next;
    			}
    			pre->next=p->next;//前一个节点与当前不同节点连接
    			p=pre->next;//当前处理节点往前移动一个
    			
    		}
    		else{
    			pre=p;
    			p=p->next;
    		}
    	}
    	return head->next;
    }
};