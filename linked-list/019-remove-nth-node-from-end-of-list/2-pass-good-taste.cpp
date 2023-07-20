class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode **ptr = &head; // it is not necessary to use indirect pointer here
    int length = 0;

    // Calculate the length of the linked list
    while (*ptr) {
      length++;
      ptr = &(*ptr)->next;
    }

    /* Using indirect pointer, we do not need to handle edge case.
     * it can be see as "fake head"
     *
     * // Edge case: Remove the head node
     * if (n == length) {
     *   ListNode *temp = head;
     *   head = head->next;
     *   delete temp;
     *   return head;
     * }
     */

    // Regular case: Find the node to be removed and adjust the pointers
    int targetPos = length - n;
    ptr = &head;
    while (targetPos) {
      ptr = &(*ptr)->next;
      targetPos--;
    }

    ListNode *temp = *ptr;
    *ptr = temp->next;
    delete temp;

    return head;
  }
};
