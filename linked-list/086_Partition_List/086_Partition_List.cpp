tion for singly-linked list.
 * struct ListNode {
  *int val;
  *ListNode *next;
  *ListNode()
      : val(0),
  next(nullptr){} * ListNode(int x)
      : val(x),
  next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){} *
};
* / class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if (!head) return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *tail_lt = dummy;
    ListNode *prev = dummy;
    ListNode *curr = head;
    ListNode *peek;

    while (curr && curr->val < x) {
      curr = curr->next;
      prev = prev->next;
    }
    tail_lt = prev;

    while (curr) {
      peek = curr->next;

      if (curr->val < x) {
        curr->next = tail_lt->next;
        tail_lt->next = curr;
        tail_lt = tail_lt->next;
        prev->next = peek;
        curr = peek;
      } else {
        prev = curr;
        curr = peek;
      }
    }
    return dummy->next;
  }
};
