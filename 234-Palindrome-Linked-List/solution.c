/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return true;
    }
    struct ListNode *slow, *fast, *rhead=NULL, *tmp;
    slow = fast= head;
    
    while(fast->next!= NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = slow->next;
    while(slow != NULL) {
        if(rhead == NULL){
            rhead =slow;
            slow = slow->next;
            rhead->next = NULL;
        }else{
            tmp = slow;
            slow = slow->next;
            tmp->next = rhead;
            rhead = tmp;
        }
    }
    while(rhead!=NULL) {
        if(rhead->val != head->val){
            return false;
        }
        rhead = rhead->next;
        head = head->next;
    }
    return true;
}