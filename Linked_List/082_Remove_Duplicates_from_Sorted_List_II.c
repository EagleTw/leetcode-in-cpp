/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode **slow = &head,
                    **fast = &head;

    while (*fast) {
        fast = &(*fast)->next;
        while(*fast && (*slow)->val == (*fast)->val)
            fast = &(*fast)->next;
        if (&((*slow)->next) == fast)
            slow = &((*slow)->next);
        else
            *slow = *fast;
    }

    return head;
}
