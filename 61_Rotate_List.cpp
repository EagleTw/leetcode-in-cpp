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
  ListNode *rotateRight(ListNode *head, int k) {

    if (!head)
      return nullptr;
    if (k == 0)
      return head;

    ListNode *curr = head;
    int len = 1;
    while (curr->next) {
      curr = curr->next;
      len++;
    }
    cout << len << endl;

    curr->next = head;

    if (k %= len) {
      for (int i = 0; i < len - k; i++)
        curr = curr->next;
    }
    head = curr->next;
    curr->next = nullptr;

    return head;
  }
};
