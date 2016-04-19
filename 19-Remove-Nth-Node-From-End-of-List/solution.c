/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    struct ListNode *p = head, *q= head;
    while(q!= NULL){
        q = q->next;
        if(i>n) {
            p = p->next;
        }
        i++;
    }
    //Move to the end
    if(n<i) {
        struct ListNode *willDelete;
        willDelete = p->next;
        p->next = p->next->next;
    }else{
        head = head->next;
        free(p);
        p = NULL;
    }
    return head;
}