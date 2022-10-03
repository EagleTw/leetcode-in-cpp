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
  ListNode *reverseBetween(ListNode *head, int left, int right) {

    if (!head || !head->next)
      return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = dummy;
    for (int i = 0; i < left - 1; i++) {
      curr = curr->next;
    }

    ListNode *end_of_first = curr;

    curr = curr->next;
    ListNode *end_of_second = curr;

    ListNode *prev = nullptr;
    ListNode *forward = nullptr;

    for (int i = left; i <= right; i++) {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }
    end_of_first->next = prev;
    end_of_second->next = curr;

    return dummy->next;
  }
};
