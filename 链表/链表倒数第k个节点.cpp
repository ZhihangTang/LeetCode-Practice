//找到链表倒数第k个节点：实现一个算法，找出单向列表中倒数第k个节点
  ListNode* findKthNode(ListNode* head,int k){
    ListNode* slow=head;
    ListNode* fast=head;
    while(k--){
      if(fast){
        fast=fast->next;
      }
      else{
        return NULL;
      }
      while(fast){
        fast=fast->next;
        slow=slow->next;
      }
      return slow;