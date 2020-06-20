/*
206. 反转链表
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p=NULL;              //尾节点
        ListNode* cur=head;
        while(cur){
            ListNode* tmp=cur->next;  //临时变量保存下一个处理的节点
            cur->next=p;              //当前节点的下一节点设置为尾节点
            p=cur;                    //尾部节点移动到当前节点
            cur=tmp;                  //当前节点移动到下一节点
        }
        return p;
    }
};

//2、反转从位置 m 到 n 的链表。请使用一趟扫描完成反转
class Solution {
public:
    ListNode* reverseList(ListNode* head,int m,int n) {
        ListNode* p=head;       //m位置的节点
        ListNode* q=head;       //n位置的节点
        while(m){
            p=p->next;
            m--;
        }
        while(n){
            q=q->next;
            n--;
        }

        while(count<n-m+1){
            ListNode* tmp=p->next;  //临时变量保存下一个处理的节点
            p->next=q;              //当前节点的下一节点设置为尾节点
            q=cur;                    //尾部节点移动到当前节点
            p=tmp;                  //当前节点移动到下一节点
        }
        return head;
    }
};

//
/*3
25. K 个一组翻转链表
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。



示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5*/


//思路，递归
我的递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p;
        ListNode* cur=head;
        int n=0;
        while(cur){
            cur=cur->next;
            if(++n>k) break;
        }
        if (n < k) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        for(int i=0;i<k;++i){
            ListNode* tmp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tmp;
        }

        head->next=reverseKGroup(curr, k);
        return prev;
    }

};
思路2：将链表分为k个一组，分别表用reverse函数，然后再首尾拼接起来。

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {


        ListNode* hair=new ListNode(0);
        hair->next=head;//输出hair->next;
        ListNode* pre=hair;

        while(head){
            ListNode* tail=pre;
            for(int i=0;i<k;++i){
                tail=tail->next;
                if(!tail) return hair->next;
            }

            ListNode* nxt=tail->next;
            pair<ListNode*,ListNode*> result=reverse(head,tail);
            head=result.first;
            tail=result.second;
            pre->next=head;
            tail->next=nxt;
            pre=tail;
            head=tail->next;

        }
        return hair->next;
    }

    pair<ListNode*,ListNode*> reverse(ListNode* head,ListNode* tail){
        ListNode* p=tail->next;
        ListNode* cur=head;
        while(p!=tail){
            ListNode* tmp=cur->next;
            cur->next=p;
            p=cur;
            cur=tmp;

        }
        return make_pair(tail,head);
    }

};
