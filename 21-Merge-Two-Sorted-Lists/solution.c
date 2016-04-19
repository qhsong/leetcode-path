/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL && l2==NULL){
        return NULL;
    }
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    struct ListNode *head,*p;
    head = p = (struct ListNode *)malloc(sizeof(struct ListNode));
    
    while(l1!= NULL || l2 != NULL) {
        if(l1 == NULL) {
            while(l2 != NULL) {p->next = l2;l2 = l2->next;p=p->next;}
            break;
        }
        if(l2 == NULL) {
            while(l1 != NULL) {p->next = l1;l1 = l1->next;p=p->next;}
            break;
        }
        
        if(l1->val > l2->val) {
            p->next = l2;
            l2 = l2->next;
        }else{
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    p = head;
    head = head->next;
    free(p);
    p = NULL;
    
    return head;
}