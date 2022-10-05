/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

    struct ListNode **indirect = &head;

    while (*indirect) {
        if ((*indirect)->val == val) {
            *indirect = (*indirect)->next;
        }
        else {
            indirect = &(*indirect)->next;
        }
    }
    return head;
}
