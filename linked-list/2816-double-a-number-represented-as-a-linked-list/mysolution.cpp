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
  ListNode *doubleIt(ListNode *head) {
    ListNode *dummy = new ListNode(0, head);

    recurDouble(dummy);
    if (!dummy->val) {
      delete dummy;
      return head;
    }
    return dummy;
  }

private:
  int recurDouble(ListNode *head) {
    if (!head)
      return 0;

    const int carry = recurDouble(head->next);
    head->val = head->val * 2 + carry;
    if (head->val / 10) {
      head->val %= 10;
      return 1;
    }
    return 0;
  }
};
