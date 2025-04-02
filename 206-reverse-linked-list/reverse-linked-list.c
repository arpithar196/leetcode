/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp=head;
    struct ListNode* prev=NULL;
    while(head!=NULL){
        temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
    
}