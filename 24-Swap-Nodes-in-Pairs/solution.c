/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*
 
//False, we should not modify the value of list
//Hack way
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p=head;
    while(p!= NULL && p->next != NULL) {
        int tmp;
        tmp = p->next->val;
        p->next->val = p->val;
        p->val = tmp;
        p = p->next->next;
    }
    return head;
}
*/
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *r,*p, *q;
    r = p = q = head;
    while(p && p->next) {
        q = p->next;
        p->next = q->next;
        q->next = p;
        if(p == head) {
            head = q;
        }else{
            r->next = q;
        }
        r = p;
        p = p->next;
    }
    return head;
}


