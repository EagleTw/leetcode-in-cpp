/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;

    ListNode newHead(0);
    ListNode *p = &newHead;

    int carry = 0;

    while (p1 || p2 || carry) {
      int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
      p->next = new ListNode(0);
      p = p->next;

      p->val = sum % 10;
      carry = sum / 10;
      if (p1)
        p1 = p1->next;
      if (p2)
        p2 = p2->next;
    }
    return newHead.next;
  }
};
