/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (!head)
      return nullptr;

    std::unordered_map<Node *, Node *> m;

    Node *h2 = new Node(head->val);
    Node *p1 = head;
    Node *p2 = h2;
    m[head] = h2;
    while (p1->next) {
      p2->next = new Node(p1->next->val);
      m[p1->next] = p2->next;
      p2 = p2->next;
      p1 = p1->next;
    }

    p2 = h2;
    p1 = head;
    while (p1 && p2) {
      p2->random = m[p1->random];
      p1 = p1->next;
      p2 = p2->next;
    }

    return h2;
  }
};
