/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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