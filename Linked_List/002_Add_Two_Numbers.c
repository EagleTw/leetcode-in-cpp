/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  // use indirect pointer technique

  struct ListNode *p1 = l1, *p2 = l2, *result = NULL, **rptr = &result;

  int sum = 0;

  while (p1 || p2 || sum) {
    if (p1) {
      sum += p1->val;
      p1 = p1->next;
    }
    if (p2) {
      sum += p2->val;
      p2 = p2->next;
    }

    *rptr = malloc(sizeof(struct ListNode));
    (*rptr)->val = sum % 10;
    (*rptr)->next = NULL;
    rptr = &(rptr)->next;
    sum /= 10;
  }
  return result;
}
