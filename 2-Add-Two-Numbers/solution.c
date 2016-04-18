/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL || l2 == NULL){
        if(l1 == NULL && l2 != NULL) {
            return l2;
        }
        if(l1 != NULL && l2 == NULL) {
            return l1;
        }
        if(l1 == NULL && l2== NULL) {
            return NULL;
        }
    }
    
    struct ListNode *header, *p;
    header = p =NULL;
    int carry = 0;
    while(l1!= NULL || l2!= NULL) {
        int il1 = 0,il2 = 0;
        if(l1 != NULL) il1 = l1->val;
        if(l2 != NULL) il2 = l2->val;
        if(p == NULL){  //First call
            header = p = (struct ListNode *)malloc(sizeof(struct ListNode));
        }else{  //Other call
            p->next =  (struct ListNode *)malloc(sizeof(struct ListNode));
            p = p->next;
        }
        p->next = NULL;
        
        p->val = (il1+ il2 + carry)%10;
        carry = (il1+ il2 + carry)/10;
        
        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
    }
    if (carry != 0) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = carry;
        p->next = NULL;
    }
    return header;
}