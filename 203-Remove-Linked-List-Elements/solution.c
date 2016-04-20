/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p, *q;
    p = q = head;
    while(p!= NULL) {
        if(p->val == val){
            if(p==head) {
                head = head->next;
                free(p);
                p = q = head;
            }else{
                q->next = p->next;
                free(p);
                p = q->next;
            }
        }else{
            q = p;
            p = p->next;
        }
    }
    return head;
}