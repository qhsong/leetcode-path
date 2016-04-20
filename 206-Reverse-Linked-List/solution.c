/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    
    struct ListNode *p, *rhead=NULL, *tmp;
    p = head;
    while(p != NULL) {
        if(rhead == NULL) {
            rhead = p;
            p = p->next;
            rhead->next = NULL;
        }else{
            tmp = p;
            p = p->next;
            tmp->next = rhead;
            rhead = tmp;
        }
    }
    return rhead;
}