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
  ListNode *reverse(ListNode *head) {
    if (!head) return nullptr;

    ListNode *prev = nullptr, *curr = head, *forward = head->next;

    while (forward) {
      curr->next = prev;
      prev = curr;
      curr = forward;
      forward = forward->next;
    }
    curr->next = prev;
    head = curr;

    return head;
  }

 public:
  void reorderList(ListNode *head) {
    int len = 0;
    for (ListNode *it = head; it != nullptr; it = it->next) {
      len++;
    }

    int cnt = 0;

    // cut the whole linked list into two list;
    ListNode *a = head;
    ListNode *b;
    for (ListNode *it = head; it != nullptr; it = it->next) {
      cnt++;
      if (cnt >= len / 2) {
        b = it->next;
        it->next = nullptr;
      }
    }

    // reverse linked list
    b = reverse(b);

    // consturct return list
    ListNode *h = new ListNode(0);
    while (a || b) {
      if (a) {
        h->next = a;
        a = a->next;
        h = h->next;
      }
      if (b) {
        h->next = b;
        b = b->next;
        h = h->next;
      }
    }

    return;
  }
};
