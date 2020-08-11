// 160.编写一个程序，找到两个单链表相交的起始节点。

// 如下面的两个链表：


class solution
{
public:
	ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
		ListNode* p1=headA;
		ListNode* p2=headB;
		int len1=0,len2=0;
		while(p1){
			len1++;
			p1=p1->next;
		}
		while(p2){
			len2++;
			p2=p2->next;
		}
		//len1长的,len2短的
		if(len2>len1){
			p1=headB;
			p2=headA;
		}
		int dif=abs(len2-len1);
		while(dif){
			p1=p1->next;
		}
		while(p1!=p2){
			p1=p1->next;
			p2=p2->next;
		}
		return p1;
	}
	
};