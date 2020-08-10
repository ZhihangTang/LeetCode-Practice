/*
141. 环形链表
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数pos来表示链表尾连接到链表中的位置（索引从 0 开始）。
 如果 pos是 -1，则在该链表中没有环。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
思路：使用快慢指针，如果有环，肯定会重合。否则会到链表尾部，返回false
*/
  // Definition for singly-linked list.
 struct ListNode {
 	int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class solution{
public:
	bool hashCycle(ListNode* head){
		if(head==NULL||head->next==NULL) return false;
		ListNode* slow=head;
		ListNode* fast=head->next;
		while(l1!=l2){
			if(fast==NULL||fast->next==NULL) return false;
			slow=l1->next;
			fast=fast->next->next;
		}
		return true;
	}
}