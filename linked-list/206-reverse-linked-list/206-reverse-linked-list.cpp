class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return NULL;
    }
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
      ListNode* n = curr->next;
      curr->next = prev;
      prev = curr;
      curr = n;
    }

    head = prev;

    return head;
  }
};
