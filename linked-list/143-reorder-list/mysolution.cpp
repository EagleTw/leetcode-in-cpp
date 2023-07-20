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
  void reorderList(ListNode *head) {
    // split list into two
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *h1 = head;
    ListNode *h2 = reverse(slow->next);
    slow->next = nullptr;

    while (h1 && h2) {
      ListNode *nh1 = h1->next;
      ListNode *nh2 = h2->next;
      h1->next = h2;
      h2->next = nh1;
      h1 = nh1;
      h2 = nh2;
    }
  }

private:
  ListNode *reverse(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *prev = head;
    ListNode *cur = head->next;
    ListNode *next = cur;
    while (cur) {
      next = next->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    head->next = nullptr;
    return prev;
  }
};
