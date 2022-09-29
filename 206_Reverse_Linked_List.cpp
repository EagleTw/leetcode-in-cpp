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
  ListNode *reverseList(ListNode *head) {

    if (head == nullptr) {
      return NULL;
    }

    ListNode *prev = nullptr, *lookahead = head->next;

    while (lookahead != nullptr) {
      head->next = prev;
      prev = head;
      head = lookahead;
      lookahead = head->next;
    }
    head->next = prev;

    return head;
  }
};
