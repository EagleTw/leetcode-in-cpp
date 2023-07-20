class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head;
    ListNode **slow = &head;
    int length = 0;

    /* Fast pointer moves n steps first, and then slow pointer starts moving.
     * When fast pointer reaches tail, slow pointer is n-th node from the end.*/

    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }

    while (fast) {
      slow = &(*slow)->next;
      fast = fast->next;
    }

    ListNode *temp = *slow;
    *slow = temp->next;
    delete temp;

    return head;
  }
};
